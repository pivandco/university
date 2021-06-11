using System;
using System.Linq;

namespace Loops._10
{
	class Program
	{
		private const int MaxArraySize = 10000;

		static void Main()
		{
			var nNums = GetAmountOfNumbers();
			var nums = GenerateNums(nNums);
			Console.WriteLine(string.Join(' ', nums));
			Console.WriteLine($"Произведение: {nums.Aggregate(1, (acc, x) => acc * x)}");
		}

		static int GetAmountOfNumbers()
		{
			int nNums;
			do
			{
				Console.Write($"Количество чисел (1 - {MaxArraySize}): ");
				int.TryParse(Console.ReadLine(), out nNums);
			} while (nNums is > MaxArraySize or < 1);

			return nNums;
		}

		static int[] GenerateNums(int amount)
		{
			var random = new Random();
			return (from n in Enumerable.Range(0, amount) select random.Next(1, 10)).ToArray();
		}
	}
}
