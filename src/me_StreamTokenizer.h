// Input stream tokenizer

/*
  Author: Martin Eden
  Last mod.: 2025-09-10
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_StreamTokenizer
{
  // [Internal] Input stream with Vomit()
  class TVomitableInputStream : public IInputStream
  {
    public:
      void Init(IInputStream *);

      TBool Read(TUnit *) override;

      TBool Vomit();

    private:
      IInputStream * InputStream;
      TUnit UnitRead;
      TBool HasUnitRead;
      TBool UseUnitRead;
  };

  // Get entity from input stream and write it to output stream
  TBool GetEntity(IOutputStream *, IInputStream *);

  // Freetown
  namespace Freetown
  {
    void SkipSpaces(TVomitableInputStream *);
    TBool WriteNonSpaces(IOutputStream *, TVomitableInputStream *);

    TBool IsSpace(TUint_1 Char);
  }
}

/*
  2025-08-31
  2025-09-04
  2025-09-10 Interface change
*/
