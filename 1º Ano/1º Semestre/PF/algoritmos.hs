module Algoritmos where




import Data.Char




merge :: [Integer] -> [Integer] -> [Integer]
merge a [] = a
merge [] b = b
merge a b | (head a) <= (head b) = [head a] ++ (merge (tail a) b)
          | otherwise = [head b] ++ (merge a (tail b))

mergeSort :: [Integer] -> Int -> Int -> [Integer]
mergeSort a l r | l < r = let m = div (l + r) 2
                          in (merge (mergeSort a l m) (mergeSort a (m + 1) r))
                | l == r = [last (take l a)]
                | otherwise = []


posImpares :: [a] -> [a]
posImpares (x:y:t) = y : posImpares t
posImpares _ = []


concat' :: [[a]] -> [a]
concat' [] = []
concat' ([]:t) = concat' t
concat' ((x:xs):t) = x : concat' (xs:t)

unlines' :: [String] -> String
unlines' [] = ""
unlines' (x:xs) = x ++ "\n" ++ unlines' xs


isSorted :: Ord a => [a] -> Bool
isSorted [x] = True
isSorted (x:y:xs) | x > y     = False
                  | otherwise = isSorted (y:xs)


maybes :: [Maybe a] -> [a]
maybes [] = []
maybes ((Just a):t) = a : maybes t
maybes ((Nothing):t) = maybes t



rev :: [a] -> [a]
rev [] = []
rev (x:xs) = rev xs ++ [x]

dropp :: Int -> [a] -> [a]
dropp 0 a = a
dropp n [] = []
dropp n (x:xs) = drop (n - 1) xs



words' :: String -> [String]
words' [] = []
words' s = let str = dropWhile isSpace s
               (f, t) = break isSpace str
            in case f of
                [] -> words' t
                _ -> f : words' t 