import Data.Char


fact :: Integer -> Integer
fact 0 = 1
fact x = x * fact (x - 1)

--1------------------------------------------
---------------------------------------------

--(a) (b)  [6,12,18] = [x | x <- [1..29], mod x 6 == 0]
--(c)  [(10, 20), (11, 19), (12,18), ..., (20,10)]  = [(x,y) | x <- [10,20], y <- [10,20], x + y == 30]
-- (d) [1,1,4,4,9,9,16,16,25,25] [x^2 | x <- [1,1,2,2,3,3,4,4,5,5]]


--2------------------------------------------
---------------------------------------------

-- (a)    [2^x | x <- [0..10]]
-- (b)    [(x,y) | x <- [1..5], y <- [1..5], x+y == 6]
-- (c)    [[x | x <- [1..y]] | y <- [1..5]]
-- (d)    [[x | x <- take y (repeat 1)] | y <- [1..5]]
-- (e)    [fact x | x <- [1..6]]


digitAlpha :: String -> (String, String)
digitAlpha "" = ("","")
digitAlpha (x:xs)
                | isDigit x = (a, x : b) 
                | isAlpha x = (x : a, b)
                | otherwise = (a, b)
                where (a, b) = digitAlpha xs


nzp :: [Int] -> (Int, Int, Int)
nzp [] = (0, 0, 0)
nzp (x:xs)
        | x < 0  = (a + 1, b, c)
        | x == 0 = (a, b + 1, c)
        | x > 0  = (a, b, c + 1)
        where (a, b, c) = nzp xs


divMod' :: Integral a => a -> a -> (a, a)
divMod' a b 
        | a < b      = (0, a)
        | otherwise  = (1 + c, d)
        where (c, d) = divMod' (a - b) b




fromDigitsAux :: [Int] -> Int -> (Int, Int)
fromDigitsAux [] _ = (0,0)
fromDigitsAux [h] _ = (h,1)
fromDigitsAux (x:xs) t = (x * 10 ^ v + n, v+1)
                        where (n,v) = fromDigitsAux xs t


fromDigits :: [Int] -> Int
fromDigits a = fst $ fromDigitsAux a 0


maxSumInitAux :: (Num a, Ord a) => [a] -> a -> a -> a
maxSumInitAux [] mx cur = mx
maxSumInitAux (x:xs) mx cur
                        | x + cur > mx = maxSumInitAux xs (x + cur) (x + cur)
                        | otherwise    = maxSumInitAux xs mx (x + cur)


maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit a  = maxSumInitAux a 0 0




fib' :: Int -> Int -> Int -> Int
fib' 0 a b = a + b
fib' n a b = fib' (n - 1) (a + b) a



fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib a = fib' (a - 1) 1 0