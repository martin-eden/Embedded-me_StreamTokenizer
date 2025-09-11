// Input stream tokenizer implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-11
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_StreamTools.h>

using namespace me_StreamTokenizer;

/*
  Get entity from stream
*/
TBool me_StreamTokenizer::GetEntity(
  IOutputStream * OutputStream,
  IInputStream * InputStream
)
{
  me_StreamTools::TVomitableInputStream VomitableStream;

  VomitableStream.Init(InputStream);

  Freetown::SkipSpaces(&VomitableStream);

  return Freetown::WriteNonSpaces(OutputStream, &VomitableStream);
}

/*
  2025-08-31
  2025-09-01
  2025-09-04
  2025-09-05
  2025-09-10
*/
