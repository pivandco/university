
main = do
    putStr "Количество секунд: "
    sStr <- getLine
    print $ secondsToTime (read sStr :: Int)

data Time = Time {
    days :: Int,
    hours :: Int,
    minutes :: Int,
    seconds :: Int
}

instance Show Time where
    show t = paste days ++ " дней, " ++ paste hours ++ " часов, " ++ paste minutes ++ " минут, " ++ paste seconds ++ " секунд"
        where paste = \f -> show $ f t

secondsToTime :: Int -> Time
secondsToTime s = Time { days = days, hours = hours, minutes = minutes, seconds = seconds }
    where
        seconds = s `mod` 60
        minutes = s `div` 60 `mod` 60
        hours = s `div` 3600 `mod` 24
        days = s `div` 3600 `div` 24
