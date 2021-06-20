main = putStrLn $ show beans ++ " лет"
    where
        beans = required `div` avgCollection
        required = truncate $ 2^64 - 1
        avgCollection = truncate $ 7E7 * 1000 * 1000 * 10
