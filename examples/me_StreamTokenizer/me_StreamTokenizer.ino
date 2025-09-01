// [me_StreamTokenizer] test

/*
  Author: Martin Eden
  Last mod.: 2025-09-01
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_StreamsCollection.h>

void RunCompilationTest()
{
  [[gnu::unused]] me_StreamTokenizer::TStreamTokenizer StreamTokenizer;
}

void PrintSeg(
  TAsciiz Label,
  TAddressSegment AddrSeg
)
{
  me_StreamsCollection::TWorkmemInputStream MemStream;
  TUnit Unit;

  MemStream.Init(AddrSeg);

  Console.Write(Label);
  Console.Write(" (");

  while (MemStream.Read(&Unit))
    Console.Print(Unit);

  Console.Write(")");
  Console.EndLine();
}

void WriteEntityTest()
{
  me_StreamTokenizer::TStreamTokenizer StreamTokenizer;
  me_StreamsCollection::TWorkmemInputStream InputStream;
  me_StreamsCollection::TWorkmemOutputStream OutputStream;

  TUnit DataIn[] = { ' ', 'A', ' ', ' ', 'B', 'b', ' ', 'C' };
  TUnit DataOut[5] = { 0 };

  TAddressSegment DataInSeg =
    { .Addr = (TAddress) &DataIn, .Size = sizeof(DataIn) };

  TAddressSegment DataOutSeg =
    { .Addr = (TAddress) &DataOut, .Size = sizeof(DataOut) };

  PrintSeg("Input", DataInSeg);

  InputStream.Init(DataInSeg);
  OutputStream.Init(DataOutSeg);

  StreamTokenizer.Init(&InputStream);

  while (StreamTokenizer.WriteEntity(&OutputStream))
    PrintSeg("Output", DataOutSeg);
}

void RunTests()
{
  RunCompilationTest();
  WriteEntityTest();
}

void setup()
{
  Console.Init();

  Console.Print("( [me_StreamTokenizer] test");

  RunTests();

  Console.Print(") Done");
}

void loop()
{
}

/*
  2025-08-31
*/
