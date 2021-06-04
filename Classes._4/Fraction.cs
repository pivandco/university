using System;
using System.Numerics;

namespace Classes._4
{
    internal readonly struct Fraction
    {
        public BigInteger Numerator { get; }

        public BigInteger Denominator { get; }

        public Fraction(BigInteger numerator, BigInteger denominator)
        {
            Numerator = numerator;
            Denominator = denominator;
            ThrowIfDenominatorIsZero();
        }

        private void ThrowIfDenominatorIsZero()
        {
            if (Denominator == 0)
            {
                throw new ArgumentException("Zero denominator is not allowed");
            }
        }

        public Fraction Reduced()
        {
            var d = BigInteger.GreatestCommonDivisor(Numerator, Denominator);
            return new Fraction(Numerator / d, Denominator / d);
        }

        public Fraction Flipped() => new(Denominator, Numerator);

        public static bool operator ==(Fraction a, Fraction b) =>
            a.Numerator == b.Numerator && a.Denominator == b.Denominator;

        public static bool operator !=(Fraction a, Fraction b) => !(a == b);

        public override bool Equals(object obj)
        {
            if (obj is not Fraction other) return false;
            var thisReduced = Reduced();
            var otherReduced = other.Reduced();
            return thisReduced.Numerator == otherReduced.Numerator &&
                   thisReduced.Denominator == otherReduced.Denominator;
        }

        public override int GetHashCode() => HashCode.Combine(Numerator, Denominator);

        public static Fraction operator +(Fraction a) => new(a.Numerator, a.Denominator);

        public static Fraction operator -(Fraction a) => new(-a.Numerator, a.Denominator);

        public static Fraction operator +(Fraction a, Fraction b) =>
            new Fraction(
                a.Numerator * b.Denominator + b.Numerator * a.Denominator,
                a.Denominator * b.Denominator
            ).Reduced();

        public static Fraction operator -(Fraction a, Fraction b) => a + -b;

        public static Fraction operator *(Fraction a, Fraction b) =>
            new Fraction(a.Numerator * b.Numerator, a.Denominator * b.Denominator).Reduced();

        public static Fraction operator /(Fraction a, Fraction b)
        {
            if (b.Numerator == 0)
            {
                throw new DivideByZeroException($"{nameof(b)} is 0");
            }
            return a * b.Flipped();
        }

        public override string ToString()
        {
            var asString = $"{BigInteger.Abs(Numerator)}/{BigInteger.Abs(Denominator)}";
            var negative = Numerator * Denominator < 0;
            if (negative)
            {
                asString = "-" + asString;
            }

            return asString;
        }
    }
}
