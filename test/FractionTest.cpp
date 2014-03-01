#include <sstream>
using namespace std;

#include <bandit/bandit.h>
using namespace bandit;

#include "fraction.h"

go_bandit([]() {

    describe("分数", []() {

        it("デフォルトコンストラクタ", []() {
            AssertThat(Fraction(), Equals(Fraction(0,1)));
          });

        it("足し算", []() {
            AssertThat(Fraction(1,6) + Fraction(1,3),
                       Equals(Fraction(1,2)));
          });

        it("約分", []() {
            AssertThat(Fraction(6,8),   Equals(Fraction(3,4)));
            AssertThat(Fraction(-2,5),  Equals(Fraction(2,-5)));
            AssertThat(Fraction(-3,-7), Equals(Fraction(3,7)));
            AssertThat(Fraction(0,1),   Equals(Fraction(0,2)));
          });

        describe("出力", []() {
            it("正数", [&]() {
                ostringstream sout;
                sout << Fraction(2,7);
                AssertThat(sout.str(), Equals("2/7"));
              });
            it("負数", [&]() {
                ostringstream sout;
                sout << Fraction(2,-7);
                AssertThat(sout.str(), Equals("-2/7"));
              });
            it("約分", [&]() {
                ostringstream sout;
                sout << Fraction(6,8);
                AssertThat(sout.str(), Equals("3/4"));
              });
          });
      });
  });
