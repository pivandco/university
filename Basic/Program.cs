using System;
using static System.Math;

namespace Basic
{
    class Program
    {
        static void Main(string[] args)
        {
            SecondsToTime();
            LotOfSeeds();
            LongExpression();
            AngleBetweenArrows();

            Console.ReadLine();
        }

        private static void SecondsToTime()
        {
            var inSeconds = 90400;

            var seconds = inSeconds % 60;
            var minutes = inSeconds / 60 % 60;
            var hours = inSeconds / 3600 % 24;
            var days = inSeconds / 3600 / 24;
        }

        private static void LotOfSeeds()
        {
            var requiredSeeds = Pow(2, 64) - 1;
            var averageCollectionSeed = 7e7 * 1000 * 1000 * 10;
            var years = Round(requiredSeeds / averageCollectionSeed, MidpointRounding.ToPositiveInfinity);
            Console.WriteLine(years);
        }

        private static void LongExpression()
        {
            double a = 0.5, b = 0.5;

            var y = Sqrt(Abs(Pow(a, Pow(Sin(b), 2.0) + Cos(Pow(b, 3.0))) + Cbrt(Pow(b, 2.0))) /
                Pow(Abs(a * Tan(b) / (1.0 - Pow(E, Sqrt(a)))), 0.25));
        }

        private static void AngleBetweenArrows()
        {
            const double oneMinuteDeg = 360 / 60;
            const double oneHourDeg = 360 / 12;
            const double offsetDeg = oneHourDeg / 60;

            int hours = 14, minutes = 30;

            var minAngle = oneMinuteDeg * minutes;
            var hourAngle = oneHourDeg * (hours % 12) + offsetDeg * minutes;

            var angle = Abs(minAngle - hourAngle);
            if (angle >= 180)
            {
                angle = 360 - angle;
            }
        }
    }
}
