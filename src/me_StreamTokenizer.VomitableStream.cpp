// Vomitable input stream implementation

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
void TVomitableInputStream::Init(
  IInputStream * BaseInputStream
)
{
  InputStream = BaseInputStream;
  HasUnitRead = false;
  UseUnitRead = false;
}

/*
  Vomit

  Put last character we ate back.
*/
TBool TVomitableInputStream::Vomit()
{
  if (HasUnitRead)
    UseUnitRead = true;

  return HasUnitRead;
}

/*
  Read

  We're caching unit read to be able to put it back in Vomit().
*/
TBool TVomitableInputStream::Read(
  TUnit * Unit
)
{
  if (UseUnitRead)
  {
    *Unit = UnitRead;
    HasUnitRead = false;

    UseUnitRead = false;

    return true;
  }

  if (InputStream->Read(&UnitRead))
  {
    *Unit = UnitRead;
    HasUnitRead = true;

    return true;
  }

  return false;
}

/*
  2025-08-31
  2025-09-01
*/
