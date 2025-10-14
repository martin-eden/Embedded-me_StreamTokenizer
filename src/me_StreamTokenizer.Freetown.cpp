// Stream tokenizer low-level functions

/*
  Author: Martin Eden
  Last mod.: 2025-10-14
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_StreamTokenizer;

/*
  Skip spaces

  Read characters from stream until non-space character or end of stream.
  Next character read will be first non-space character or end of stream.
*/
void Freetown::SkipSpaces(
  TInputStream * InputStream
)
{
  TUnit Char;

  while (InputStream->Read(&Char))
  {
    if (!Freetown::IsSpace(Char))
    {
      InputStream->Unread();

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
TBool Freetown::WriteNonSpaces(
  IOutputStream * OutputStream,
  TInputStream * InputStream
)
{
  TBool Result;
  TUnit Char;

  Result = false;

  while (InputStream->Read(&Char))
  {
    if (Freetown::IsSpace(Char))
    {
      InputStream->Unread();

      break;
    }

    OutputStream->Write(Char);

    Result = true;
  }

  return Result;
}

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

/*
  2025-08-31
  2025-09-01
  2025-09-04
  2025-09-05
  2025-09-10
*/
