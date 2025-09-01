// Input stream tokenizer

/*
  Author: Martin Eden
  Last mod.: 2025-08-31
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_StreamTokenizer
{
  // [Internal] Input stream with Vomit()
  class TVomitableInputStream : public IInputStream
  {
    public:
      void Init(IInputStream * BaseInputStream);

      TBool Read(TUnit * Unit) override;

      TBool Vomit();

    private:
      IInputStream * InputStream;
      TUnit UnitRead;
      TBool HasUnitRead;
      TBool UseUnitRead;
  };

  // [Core] Input stream tokenizer
  class TStreamTokenizer
  {
    public:
      // Setup input stream
      void Init(IInputStream *);

      // Read one entity and write it to output stream
      TBool WriteEntity(IOutputStream *);

    private:
      TVomitableInputStream VomitableStream;

      void SkipSpaces();
      TBool WriteNonSpaces(IOutputStream *);
  };

  // Freetown
  namespace Freetown
  {
    TBool IsSpace(TUint_1 Char);
  }
}

/*
  2025-08-31
*/
