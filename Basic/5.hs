main = do
    hours <- input "Часы" :: IO Int
    minutes <- input "Минуты" :: IO Int
    putStrLn (show (angle hours minutes) ++ " градусов")

input :: Read b => [Char] -> IO b
input prompt = do
    putStr $ prompt ++ ": "
    read <$> getLine

angle :: Int -> Int -> Double
angle hours minutes = if angle >= 180 then 360 - angle else angle
    where
        oneMinuteDeg = 360 / 60
        oneHourDeg = 360 / 12
        hourMinuteOffsetDeg = oneHourDeg / 60
        minuteAngle = oneMinuteDeg * (fromIntegral minutes :: Double)
        hourAngle = oneHourDeg * fromIntegral (hours `mod` 12) + hourMinuteOffsetDeg * fromIntegral minutes
        angle = abs $ minuteAngle - hourAngle
