import Data.List

main = do
  n <- input "Количество точек: " :: IO Int
  radius <- input "Радиус: " :: IO Double
  points <- mapM getNthPoint [1..n]
  let c = countPointCond radius points
  putStrLn ("Внутри обоих: " ++ show (c inBoth))
  putStrLn ("Вне: " ++ show (c (\r p -> not $ inBoth r p)))

input :: Read b => String -> IO b
input prompt = do
  putStr prompt
  read <$> getLine

data Point = Point Double Double
instance Show Point where
  show (Point x y) = "(" ++ show x ++ ", " ++ show y ++ ")"

getNthPoint :: Int -> IO Point
getNthPoint n = do
  inp <- input ("Координаты " ++ show n ++ " точки: ") :: IO [Char]
  let [x, y] = take 2 $ map read (words inp)
  return $ Point x y

inCircle :: Double -> Point -> Bool
inCircle r (Point x y) = x^2 + y^2 <= r^2

inSquare :: Double -> Point -> Bool
inSquare r (Point x y) = abs x <= a && abs y <= a
  where a = r * sqrt 2 / 2

inBoth :: Double -> Point -> Bool
inBoth r p = inCircle r p && inSquare r p

countPointCond :: t -> [a] -> (t -> a -> Bool) -> Int
countPointCond r p pred = length $ filter (pred r) p
