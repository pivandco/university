using System;
using Xunit;

namespace Classes._4
{
    public class FractionTests
    {
        [Fact]
        public void ExactEquality()
        {
            var frac1 = new Fraction(1, 1);
            var frac2 = new Fraction(1, 1);
            
            Assert.True(frac1 == frac2);
        }
        
        [Fact]
        public void Inequality()
        {
            var frac1 = new Fraction(2, 1);
            var frac2 = new Fraction(1, 1);
            Assert.False(frac1.Equals(frac2));
            Assert.False(frac1 == frac2);
        }

        [Fact]
        public void MathematicalEquality()
        {
            var frac1 = new Fraction(10, 5);
            var frac2 = new Fraction(2, 1);
            Assert.True(frac1.Equals(frac2));
        }

        [Fact]
        public void ReducingWithBothComponentsNegativeLeavesSigns()
        {
            var frac = new Fraction(-10, -10);

            var reduced = frac.Reduced();
            
            Assert.True(reduced == new Fraction(-1, -1));
        }
        
        [Fact]
        public void ReducingWithNegativeDenominatorLeavesSigns()
        {
            var frac = new Fraction(10, -10);

            var reduced = frac.Reduced();
            
            Assert.True(reduced == new Fraction(1, -1));
        }

        [Fact]
        public void ReduceAlreadyReduced()
        {
            var frac = new Fraction(5, 4);

            var reduced = frac.Reduced();
            
            Assert.True(frac == reduced);
        }

        [Fact]
        public void ZeroDenominatorThrows()
        {
            Assert.Throws<ArgumentException>(() => new Fraction(1, 0));
        }

        [Fact]
        public void Addition()
        {
            Assert.True(new Fraction(2, 3) + new Fraction(2, 6) == new Fraction(1, 1));
            Assert.True(new Fraction(1, 2) + new Fraction(0, 3) == new Fraction(1, 2));
        }
        
        [Fact]
        public void Subtraction()
        {
            Assert.True(new Fraction(3, 3) - new Fraction(1, 5) == new Fraction(4, 5));
        }

        [Fact]
        public void Multiplication()
        {
            Assert.True(new Fraction(10, 1) * new Fraction(1, 10) == new Fraction(1, 1));
        }

        [Fact]
        public void Division()
        {
            Assert.True(new Fraction(1, 10) / new Fraction(10, 1) == new Fraction(1, 100));
        }

        [Fact]
        public void DivisionByZero()
        {
            Assert.Throws<DivideByZeroException>(() => new Fraction(1, 1) / new Fraction(0, 1));
        }

        [Fact]
        public void ConversionToString()
        {
            Assert.Equal("1/3", new Fraction(1, 3).ToString());
            Assert.Equal("-1/3", new Fraction(-1, 3).ToString());
            Assert.Equal("-1/3", new Fraction(1, -3).ToString());
            Assert.Equal("1/3", new Fraction(-1, -3).ToString());
        }
    }
}