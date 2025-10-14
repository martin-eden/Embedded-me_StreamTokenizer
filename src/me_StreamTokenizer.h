// Input stream tokenizer

/*
  Author: Martin Eden
  Last mod.: 2025-10-14
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_StreamTokenizer
{
  // Get entity from input stream and write it to output stream
  TBool GetEntity(IOutputStream *, IInputStream *);

  // Freetown
  namespace Freetown
  {
    void SkipSpaces(TInputStream *);

    TBool WriteNonSpaces(IOutputStream *, TInputStream *);

    TBool IsSpace(TUint_1);
  }
}

/*
  2025-08-31
  2025-09-04
  2025-09-10 Interface change
  2025-09-11
*/
