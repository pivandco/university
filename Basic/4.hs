main = do
    a <- param 'a'
    b <- param 'b'
    putStrLn $ "y = " ++ show (y a b)

param :: Char -> IO Double
param name = do
    putStr $ name : ": "
    read <$> getLine

y :: Double -> Double -> Double
y a b = sqrt $ abs (num / denom)
    where
        num = a ** (sin b^2 + cos (b^3)) + b ** (2/3)
        denom = abs ((a * tan b) / (1 - exp (sqrt a))) ** (1/4)
