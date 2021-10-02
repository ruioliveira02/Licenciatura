module Teste where


import Data.Char


delete' :: Eq a => a -> [a] -> [a]
delete' _ [] = []
delete' n (x:xs) | n == x    = xs
                 | otherwise = x : (delete' n xs)


insert' :: Ord a => a -> [a] -> [a]
insert' a [] = [a]
insert' a (x:xs) | a < x     = (a:x:xs)
                 | otherwise = x : (insert' a xs)



group' :: Eq a => [a] -> [[a]]
group' [] = []
group' (x:xs) = a : (group' b)
               where (a,b) = groupAux x (x:xs)


groupAux :: Eq a => a -> [a] -> ([a], [a])
groupAux _ [] = ([],[])
groupAux a (x:xs) | a == x    = (x : b,c)
                  | otherwise = ([], (x:xs))
                  where (b,c) = groupAux a xs



constroiMSet' :: Ord a => [a] -> [(a, Int)]
constroiMSet' [] = []
constroiMSet' (x:xs) = (x,h) : constroiMSet' (drop h (x:xs))
                       where h = length ([y | y <- (x:xs), y == x])


(\\\) :: Eq a => [a] -> [a] -> [a]
(\\\) a [] = a
(\\\) a (x:xs) = (\\\) (delete' x a) xs



data Posicao = Pos Int Int deriving Show


maisCentral :: [Posicao] -> Posicao
maisCentral [a] = a
maisCentral ((Pos x y):t) | x^2 + y^2 < x1^2 + y1^2 = (Pos x y)
                          | otherwise               = (Pos x1 y1)
                          where (Pos x1 y1) = maisCentral t




isSuffixOf' :: Eq a => [a] -> [a] -> Bool
isSuffixOf' a b = isPrefixOf' (reverse a) (reverse b)


isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' [] _ = True
isPrefixOf' _ [] = False
isPrefixOf' (a:as) (x:xs) | a == x    = isPrefixOf' as xs
                          | otherwise = False




isSubsequenceOf' :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf' [] _ = True
isSubsequenceOf' _ [] = False
isSubsequenceOf' (x:xs) (y:ys) | x == y    = isSubsequenceOf' xs ys
                               | otherwise = isSubsequenceOf' (x:xs) ys




temRepetidos :: Eq a => [a] -> Bool
temRepetidos [] = False
temRepetidos (x:xs) | length ([y | y <- (x:xs), y == x]) /= 1 = True
                    | otherwise                               = temRepetidos xs



algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (x:xs) | isDigit x = x : h
                  | otherwise = h
                  where h = algarismos xs