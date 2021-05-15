using System;
using static System.Math;

namespace Basic
{
    class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine($"1. {SecondsToTime()}");
            Console.WriteLine($"2. {LotOfSeeds()}");
            Console.WriteLine($"3. {LongExpression()}");
            Console.WriteLine($"4. {AngleBetweenArrows()}");

            // for example: 7699-9904-81
            Console.WriteLine("5. Волшебный мост");
            Console.WriteLine("Money: ");
            string input = Console.ReadLine();
            if (int.TryParse(input, out int money))
            {
                Console.WriteLine(MagicBridge(money));
            }
            else
            {
                Console.WriteLine("Введены некорректные данные");
            }

            // for example: 25-3-4
            Console.WriteLine("6. Разложение");
            input = Console.ReadLine();
            if (int.TryParse(input, out int n))
            {
                Console.WriteLine(Decomposition(n));
            }
            else
            {
                Console.WriteLine("Введены некорректные данные");
            }

            Console.ReadLine();
        }

        private static string SecondsToTime()
        {
            var inSeconds = 90400;

            var seconds = inSeconds % 60;
            var minutes = inSeconds / 60 % 60;
            var hours = inSeconds / 3600 % 24;
            var days = inSeconds / 3600 / 24;
            return $"{days}d {hours}d {minutes}m {seconds}s";
        }

        private static double LotOfSeeds()
        {
            var requiredSeeds = Pow(2, 64) - 1;
            var averageCollectionSeed = 7e7 * 1000 * 1000 * 10;
            return Round(requiredSeeds / averageCollectionSeed, MidpointRounding.ToPositiveInfinity);
        }

        private static double LongExpression()
        {
            double a = 0.5, b = 0.5;

            return Sqrt(Abs(Pow(a, Pow(Sin(b), 2.0) + Cos(Pow(b, 3.0))) + Cbrt(Pow(b, 2.0))) /
                Pow(Abs(a * Tan(b) / (1.0 - Pow(E, Sqrt(a)))), 0.25));
        }

        private static double AngleBetweenArrows()
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
            return angle;
        }

        private static string MagicBridge(int money)
        {
            const int moneyToDrop = 29;


            if (money >= moneyToDrop)
            {
                int maxSum = money, startingMoney = money, walks = 0,
                    bestWalks = 0;
                do
                {
                    money -= moneyToDrop;
                    money = money % 100 * 100 + money / 100;
                    walks++;

                    if (money > maxSum)
                    {
                        maxSum = money;
                        bestWalks = walks;
                    }
                } while (money >= moneyToDrop && money != startingMoney);

                return $"Max money: {maxSum}\nBest walks: {bestWalks}";
            }
            else
            {
                return "Слишком маленькое число";
            }
        }

        private static string Decomposition(int n)
        {
            int minAbsExpr = n, maxAddendum = (int)Sqrt(n), minQ = 0, minP = 0;
            for (int p = 0; p <= maxAddendum; p++)
            {
                for (int q = p; q < maxAddendum; q++)
                {
                    int absExpr = (int)Abs(n - Pow(p, 2) - Pow(q, 2));
                    if (absExpr <= minAbsExpr)
                    {
                        minAbsExpr = absExpr;
                        minP = p;
                        minQ = q;
                    }
                }
            }

            return $"P: {minP}\nQ: {minQ}";
        }
    }
}
