// [me_StreamTokenizer] test

/*
  Author: Martin Eden
  Last mod.: 2025-11-18
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_StreamsCollection.h>
#include <me_DebugPrints.h>

void RunCompilationTest()
{
  [[gnu::unused]] TAddress GetEntityAddr = (TAddress) &me_StreamTokenizer::GetEntity;
}

void GetEntityTest()
{
  me_StreamsCollection::TWorkmemInputStream InputStream;
  me_StreamsCollection::TWorkmemOutputStream OutputStream;

  TUnit DataIn[] = { ' ', 'A', ' ', ' ', 'B', 'b', ' ', 'C' };
  TUnit DataOut[5] = { 0 };

  TAddressSegment DataInSeg = AsAddrSeg_M(DataIn);
  TAddressSegment DataOutSeg = AsAddrSeg_M(DataOut);

  me_DebugPrints::PrintMemsegData("Input", DataInSeg);

  InputStream.Init(DataInSeg);

  while (true)
  {
    OutputStream.Init(DataOutSeg);

    if (!me_StreamTokenizer::GetEntity(&OutputStream, &InputStream))
      break;

    me_DebugPrints::PrintMemsegData("Output", OutputStream.GetProcessedSegment());
  }
}

void RunTests()
{
  RunCompilationTest();
  GetEntityTest();
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
