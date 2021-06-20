main = do
    putStr "Радиус: "
    rInput <- getLine
    let r = read rInput :: Float
        circleLength = 2 * pi * r
        circleArea = pi * r^2
        sphereVolume = 4 / 3 * pi * r^3
    putStrLn $ "Длина окружности: " ++ show circleLength
    putStrLn $ "Площадь круга: " ++ show circleArea
    putStrLn $ "Объем шара: " ++ show sphereVolume
