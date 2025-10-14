// Input stream tokenizer implementation

/*
  Author: Martin Eden
  Last mod.: 2025-10-14
*/

#include <me_StreamTokenizer.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_StreamTools.h>

using namespace me_StreamTokenizer;

/*
  Get entity from stream

  Implementation reads one space after item.
  That's how we detect item end.
  That space is lost after end of this function.
*/
TBool me_StreamTokenizer::GetEntity(
  IOutputStream * OutputStream,
  IInputStream * BaseInputStream
)
{
  me_StreamTools::TRereadableInputStream InputStream;

  InputStream.Init(BaseInputStream);

  Freetown::SkipSpaces(&InputStream);

  return Freetown::WriteNonSpaces(OutputStream, &InputStream);
}

/*
  2025-08-31
  2025-09-01
  2025-09-04
  2025-09-05
  2025-09-10
*/
