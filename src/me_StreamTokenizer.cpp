// Input stream tokenizer implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-01
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>

using namespace me_StreamTokenizer;

/*
  Init
*/
void TStreamTokenizer::Init(
  IInputStream * BaseInputStream
)
{
  VomitableStream.Init(BaseInputStream);
}

/*
  Get entity

  Skip leading spaces. Write block of non-space chars.

  Returns true if wrote at least one character.
*/
TBool TStreamTokenizer::WriteEntity(
  IOutputStream * OutputStream
)
{
  SkipSpaces();

  return WriteNonSpaces(OutputStream);
}

/*
  Skip spaces

  Read characters from stream until non-space character or end of stream.
  Next character read will be first non-space character or end of stream.
*/
void TStreamTokenizer::SkipSpaces()
{
  TUnit Char;

  while (VomitableStream.Read(&Char))
  {
    if (!Freetown::IsSpace(Char))
    {
      VomitableStream.Vomit();

      break;
    }
  }
}

/*
  Write non-spaces

  While character read is not space, write it to output stream.
  Next character read will be space (or end of stream).

  Returns true if at least one character was written.
*/
TBool TStreamTokenizer::WriteNonSpaces(
  IOutputStream * OutputStream
)
{
  TBool Result;
  TUnit Char;

  Result = false;

  while (VomitableStream.Read(&Char))
  {
    if (Freetown::IsSpace(Char))
    {
      VomitableStream.Vomit();

      break;
    }

    if (!OutputStream->Write(Char))
      break;

    Result = true;
  }

  return Result;
}

// ( Freetown

/*
  Return true if character is newline or space
*/
TBool Freetown::IsSpace(
  TUint_1 Char
)
{
  return
    (Char == ' ') ||
    (Char == '\n') ||
    (Char == '\r') ||
    (Char == '\t') ||
    (Char == '\v');
}

// )

/*
  2025-08-31
  2025-09-01
*/
