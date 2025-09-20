// Input stream with waited read (in ms)

/*
  Author: Martin Eden
  Last mod.: 2025-09-20
*/

// UNUSED
/*
  This code is for sale
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

#include <me_RunTime.h>
#include <me_Duration.h>

// [Internal] Input stream trying to Read() for some time
class TPacedInputStream : public IInputStream
{
  public:
    void Init(IInputStream * BaseInputStream);
    TBool SetReadTimeout_Ms(TUint_2 Timeout_Ms);
    TBool Read(TUnit * Unit) override;
  private:
    IInputStream * InputStream;
    TUint_2 ReadTimeout_Ms;
};

/*
  Init
*/
void TPacedInputStream::Init(
  IInputStream * BaseInputStream
)
{
  InputStream = BaseInputStream;

  SetReadTimeout_Ms(15);
}

/*
  Set read timeout
*/
TBool TPacedInputStream::SetReadTimeout_Ms(
  TUint_2 Timeout_Ms
)
{
  if (Timeout_Ms > 999)
    return false;

  ReadTimeout_Ms = Timeout_Ms;

  return true;
}

/*
  Read unit
*/
TBool TPacedInputStream::Read(
  TUnit * Unit
)
{
  me_Duration::TDuration StopTime;

  if (InputStream->Read(Unit))
    return true;

  me_RunTime::Start();
  me_RunTime::SetTime({0, 0, 0, 0});

  StopTime = {0, 0, ReadTimeout_Ms, 0};

  while (me_Duration::IsLessOrEqual(me_RunTime::GetTime(), StopTime))
  {
    if (InputStream->Read(Unit))
      return true;
  }

  return false;
}

/*
  2025-08-31
*/
