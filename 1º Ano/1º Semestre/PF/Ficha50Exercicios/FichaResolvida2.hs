module Ficha where

import Data.Char
import Data.Either

enumFromTo' :: Int -> Int -> [Int]
enumFromTo' l r | l == r    = [l]
                | otherwise = l : enumFromTo' (l + 1) r


enumFromThenTo' :: Int -> Int -> Int -> [Int]
enumFromThenTo' l r m | l > m     = []
                      | otherwise = l : enumFromThenTo' r (2 * r - l) m


(+++) :: [a] -> [a] -> [a]
(+++) [] a = a
(+++) (x:xs) a = x : (xs +++ a)



(!!!) :: [a] -> Int -> a
(!!!) (x:xs) 0 = x
(!!!) (x:xs) n = (!!!) xs (n - 1)


reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]


take' :: Int -> [a] -> [a]
take' 0 _ = []
take' _ [] = []
take' n (x:xs) = x : take (n - 1) xs




drop' :: Int -> [a] -> [a]
drop' 0 a = a
drop' n (x:xs) = drop' (n - 1) xs
drop' _ [] = []



zip' :: [a] -> [b] -> [(a,b)]
zip' (a:as) (b:bs) = (a,b) : zip' as bs
zip' _ _ = []



elem' :: Eq a => a -> [a] -> Bool
elem' _ [] = False
elem' a (x:xs) | a == x    = True
               | otherwise = elem' a xs



replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' n x = x : replicate' (n - 1) x


intersperse' :: a -> [a] -> [a]
intersperse' _ [a] =  [a]
intersperse' a (x:xs) = x : a : intersperse' a xs



group' :: Eq a => [a] -> [[a]]
group' [] = []
group' (x:xs) = a : group' b
                where (a,b) = break (/= x) (x:xs)



concat' :: [[a]] -> [a]
concat' [] = []
concat' (x:xs) = x ++ concat' xs


inits' :: [a] -> [[a]]
inits' [] = [[]]
inits' (x:xs) = inits' (init (x:xs)) ++ [(x:xs)]


tails' :: [a] -> [[a]]
tails' [] = [[]]
tails' (x:xs) = (x:xs) : tails' xs



isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' [] _ = True
isPrefixOf' _ [] = False
isPrefixOf' (x:xs) (y:ys) | x == y    = isPrefixOf' xs ys
                          | otherwise = False



isSuffixOf' :: Eq a => [a] -> [a] -> Bool
isSuffixOf' [] _ = True
isSuffixOf' _ [] = False
isSuffixOf' a b | (last a) == (last b) = isSuffixOf' (init a) (init b)
                | otherwise            = False 



isSubsequenceOf' :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf' [] _ = True
isSubsequenceOf' _ [] = False
isSubsequenceOf' (a:as) (b:bs) | a == b = isSubsequenceOf' as bs
                               | otherwise = isSubsequenceOf' (a:as) bs



elemIndices' :: Eq a => a -> [a] -> [Int]
elemIndices' _ [] = []
elemIndices' a (x:xs) | a == x    = [0] ++ b
                      | otherwise = b
                      where b = map (+ 1) (elemIndices' a xs)



nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' (x:xs) | elem x b  = b
            | otherwise = x:b
            where b = nub' xs



delete' :: Eq a => a -> [a] -> [a]
delete' _ [] = []
delete' a (x:xs) | a == x    = xs
                 | otherwise = x : (delete' a xs)


(\\\) :: Eq a => [a] -> [a] -> [a]
(\\\) a [] = a
(\\\) (a:as) (x:xs) | elem a (x:xs) = (\\\) as xs
                    | otherwise     = a : ((\\\) as (x:xs))
(\\\) [] _ = []




union' :: Eq a => [a] -> [a] -> [a]
union' a [] = a
union' a (x:xs) | elem x a  = union' a xs
                | otherwise = (union' a xs) ++ [x]



intersect' :: Eq a => [a] -> [a] -> [a]
intersect' (x:xs) a | elem x a  = x : intersect' xs a
                    | otherwise = intersect' xs a
intersect' [] a = []



insert' :: Ord a => a -> [a] -> [a]
insert' a [] = [a]
insert' a (x:xs) | a < x     = a : (x:xs)
                 | otherwise = x : (insert' a xs)



unwords' :: [String] -> String
unwords' [] = ""
unwords' [a] = a
unwords' (x:xs) = x ++ " " ++ unwords' xs

unlines' :: [String] -> String
unlines' [] = ""
unlines' (x:xs) = x ++ "\n" ++ unlines' xs



pMaior :: Ord a => [a] -> Int
pMaior a = snd (pMaiorAux a)

pMaiorAux :: Ord a => [a] -> (a, Int)
pMaiorAux [a] = (a,0)
pMaiorAux (x:xs) | x > a     = (x,0)
                 | otherwise = (a, b + 1)
                 where (a,b) = pMaiorAux xs


temRepetidos :: Eq a => [a] -> Bool
temRepetidos [] = False
temRepetidos (x:xs) | length [y | y <- (x:xs), y == x] > 1 = True
                    | otherwise                            = temRepetidos xs

algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (x:xs) | isDigit x = x : algarismos xs
                  | otherwise = algarismos xs
[],[])

posImpares :: [a] -> [a]
posImpares (x:y:t) = y : posImpares t
posImpares _ = []


posPares :: [a] -> [a]
posPares (x:y:t) = x : posPares t
posPares x = x


isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted (x:xs) | length [y | y <- (x:xs), y < x] /= 0 = False
                | otherwise                            = isSorted xs



iSort :: Ord a => [a] -> [a]
iSort [] = []
iSort (x:xs) = insert' x (iSort xs)



menor :: String -> String -> Bool
menor _ [] = False
menor [] _ = True
menor (a:as) (b:bs) | a < b     = True
                    | a > b     = False
                    | otherwise = menor as bs


elemMSet :: Eq a => a -> [(a, Int)] -> Bool
elemMSet _ [] = False
elemMSet x ((a, i):t) | x == a = True
                      | otherwise = elemMSet x t



lengthMSet :: [(a,Int)] -> Int
lengthMSet [] = 0
lengthMSet ((a,i):t) = i + lengthMSet t


converteMSet :: [(a, Int)] -> [a]
converteMSet [] = []
converteMSet ((a,i):t) = (take i (repeat a)) ++ converteMSet t


insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet a [] = [(a,1)]
insereMSet a ((x,i):t) | a == x    = (a, i + 1) : t
                       | otherwise = (x,i) : insereMSet a t


removeMSet :: Eq a => a -> [(a,Int)] -> [(a, Int)]
removeMSet x ((a,i):t) | x == a && i > 1 = (a, i - 1) : t
                       | x == a          = t
                       | otherwise       = (a,i) : removeMSet x t


constroiMSet :: Ord a => [a] -> [(a,Int)]
constroiMSet [] = []
constroiMSet (x:xs) = (x, length a) : constroiMSet b
                    where (a,b) = break (/= x) (x:xs)


partitionEithers' :: [Either a b] ->  ([a], [b])
partitionEithers' [] = ([],[])
partitionEithers' ((Left a):t) = (a : c, d)
                                where (c,d) = partitionEithers' t
partitionEithers' ((Right b):t) = (c, b : d)
                                where (c,d) = partitionEithers' t


catMaybes' :: [Maybe a] -> [a]
catMaybes' [] = []
catMaybes' ((Just a):t) = a : catMaybes' t
catMaybes' ((Nothing):t) = catMaybes' t



data Movimento = Norte | Sul | Este | Oeste deriving Show

posicao :: (Int, Int) -> [Movimento] -> (Int, Int)
posicao x [] = x
posicao (x,y) (m:ms) = case m of
                            Norte -> posicao (x, y + 1) ms
                            Sul   -> posicao (x, y - 1) ms
                            Este  -> posicao (x + 1, y) ms
                            Oeste -> posicao (x - 1, y) ms



caminho :: (Int, Int) -> (Int, Int) -> [Movimento]
caminho (x1, y1) (x2, y2)
                    | x1 == x2 && y1 == y2 = []
                    | x1 == x2 && y1 < y2  = (Norte) : caminho (x1, y1 + 1) (x2, y2)
                    | x1 == x2 && y1 > y2  = (Sul) : caminho (x1, y1 - 1) (x2, y2)
                    | x1 < x2              = (Este) : caminho (x1 + 1, y1) (x2,y2)
                    | otherwise            = (Oeste) : caminho (x1 - 1, y1) (x2, y2)



vertical :: [Movimento] -> Bool
vertical (m:ms) = case m of
                    Norte -> vertical ms
                    Sul -> vertical ms
                    _ -> False
vertical [] = True


data Posicao = Pos Int Int  deriving Show

maisCentral :: [Posicao] -> Posicao
maisCentral [a] = a
maisCentral ((Pos x y):t) | x^2 + y^2 < a^2 + b^2 = (Pos x y)
                          | otherwise             = (Pos a b)
                          where (Pos a b) = maisCentral t


vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos (Pos x y) a = [(Pos c d) | (Pos c d) <- a, abs (x - c) + abs(y - d) == 1]


mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada ((Pos a b):(Pos c d):t) | b /= d    = False
                                      | otherwise = mesmaOrdenada ((Pos c d):t)
mesmaOrdenada _ = True


data Semaforo = Verde | Amarelo | Vermelho deriving Show

interseccaoOK :: [Semaforo] -> Bool
interseccaoOK a = length [y | y <- a, red y] <= 1
                where red y = case y of
                                Vermelho -> True
                                _        -> False