// Input stream tokenizer implementation

/*
  Author: Martin Eden
  Last mod.: 2025-10-14
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_StreamTokenizer;

/*
  Get entity from stream
*/
TBool me_StreamTokenizer::GetEntity(
  IOutputStream * OutputStream,
  IInputStream * BaseInputStream
)
{
  TInputStream VomitableInputStream;

  VomitableInputStream.Init(BaseInputStream);

  Freetown::SkipSpaces(&VomitableInputStream);

  return Freetown::WriteNonSpaces(OutputStream, &VomitableInputStream);
}

/*
  2025-08-31
  2025-09-01
  2025-09-04
  2025-09-05
  2025-09-10
*/
