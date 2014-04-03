#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>

/**
 * @class 分数クラス
 * @brief 分数を表現するサンプルクラス
 *
 * あくまでサンプルなので、大した実装はない
 */
class Fraction {
    friend std::ostream& operator<<(std::ostream& os, Fraction const& f);
    friend Fraction operator+(Fraction const& lhs, Fraction const& rhs);
    friend bool operator==(Fraction const& lhs, Fraction const& rhs);
public:
    /** デフォルトコンストラクタ
     *
     *  デフォルトでは０とする
     */
    Fraction() : Fraction(0, 1) {}
    /** コンストラクタ
     *
     * @param[in] num   分子
     * @param[in] denom 分母
     *
     * @exception 分母に 0 を指定すると ZeroDivisionError が投げられる
     */
    Fraction(int num, int denom);

private:
    int numerator_;
    int denominator_;

    void toLowestTerms();
};

#endif
