module Ficha2 where

import Data.Char

dobros :: [Float] -> [Float]
dobros [] = []
dobros (x:xs) = 2 * x : dobros xs

numOcorre :: Char -> String -> Int
numOcorre _ "" = 0
numOcorre ch (first:t)
                    | ch == first = 1 + numOcorre ch t
                    | otherwise   = numOcorre ch t


--Duvida em relacao a lista vazia

positivos :: [Int] -> Bool
positivos [] = True
positivos (x:xs)
                | x <= 0    = False
                | otherwise = positivos xs
               
                     
soPos :: [Int] -> [Int]
soPos [] = []
soPos (x:xs)
            | x > 0     = x : soPos xs
            | otherwise = soPos xs


somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (x:xs) 
            | x < 0     = x + somaNeg xs
            | otherwise = somaNeg xs


tresUlt :: [a] -> [a]
tresUlt [x,y] = [x,y]
tresUlt [x] = [x]
tresUlt [x,y,z] = [x,y,z]
tresUlt (x:xs) = tresUlt xs


segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((x1,x2):xs) = x2 : segundos xs

nosPrimeiros :: (Eq a) => a -> [(a, b)] -> Bool
nosPrimeiros _ [] = False
nosPrimeiros a ((x,y):xs) 
                        | a == x    = True
                        | otherwise = nosPrimeiros a xs

sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumTriplos [] = (0,0,0)
sumTriplos ((a,b,c):xs) = let (x,y,z) = sumTriplos xs in (a + x, b + y, c + z)










soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (x:xs)
                | isDigit x = x : soDigitos xs
                | otherwise = soDigitos xs


minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (x:xs)
                | isLower x = 1 + minusculas xs
                | otherwise = minusculas xs


nums :: [Char] -> [Int]
nums [] = []
nums (x:xs)
        | isDigit x = (ord x - ord '0') : nums xs
        | otherwise = nums xs










type Polinomio = [Monomio]
type Monomio = (Float, Int)


conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta x ((f, n):xs)
                | x == n    = 1 + conta x xs
                | otherwise = conta x xs


--Duvida grau do vazio
grau :: Polinomio -> Int
grau [] = 0
grau ((f, n):xs) = max n $ grau xs


selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau x ((f, n):xs)
                | x == n    = (f,n) : selgrau x xs
                | otherwise = selgrau x xs


deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((f,n):t) = (f * fromIntegral n, n - 1) : deriv t



calcula :: Float -> Polinomio -> Float
calcula _ [] = 0.0
calcula x ((f, n):xs) = f * x ^ n + calcula x xs




simp :: Polinomio -> Polinomio
simp [] = []
simp ((f, n):xs)
            | f == 0.0  = simp xs
            | otherwise = (f, n) : simp xs


mult :: Monomio -> Polinomio -> Polinomio
mult _ [] = []
mult (f1,n1) ((f2,n2):xs) = (f1*f2, n1+n2) : mult (f1,n1) xs




-- O(N*G)-----------------------------------------
--------------------------------------------------

agruparGrau :: Int -> Polinomio -> (Monomio, Polinomio)
agruparGrau n [] = ((0, n), [])
agruparGrau n ((f1,n1):xs) 
                    | n == n1   = ((f1 + f2, n2), t) 
                    | otherwise = ((f2, n2), ((f1,n1) : t))
                        where ((f2, n2), t) = agruparGrau n xs

normalizarGrau :: Int -> Polinomio -> Polinomio
normalizarGrau (-1) x = x
normalizarGrau n x = m : (normalizarGrau (n - 1) t) where (m,t) = agruparGrau n x



normalizar :: Polinomio -> Polinomio
normalizar a = simp $ normalizarGrau (grau a)  a



--Assume que o polinomio esta normalizado
somaMonomio :: Monomio -> Polinomio -> Polinomio
somaMonomio m [] = [m]
somaMonomio (f,n) ((f1,n1):xs)
                        | n == n1   = (f1 + f, n1) : xs
                        | otherwise = (f1, n1) : somaMonomio (f,n) xs



soma :: Polinomio -> Polinomio -> Polinomio
soma [] b = b
soma b [] = b
soma (m:t) b = soma t $ somaMonomio m b





produtoMonomio :: Monomio -> Polinomio -> Polinomio
produtoMonomio _ [] = []
produtoMonomio (f1, n1) ((f2, n2):xs) = (f1 * f2, n1 + n2) : produtoMonomio (f1, n1) xs


produto :: Polinomio -> Polinomio -> Polinomio
produto [] a = a
produto (x:xs) b = produto xs (produtoMonomio x b)




--Merge Sort = O(N Log N)

merge :: Polinomio -> Polinomio -> Polinomio
merge xs [] = xs
merge [] xs = xs
merge ((f,n):xs) ((f1,n1):ys) 
                        | n <= n1   = (f,n) : merge xs ((f1,n1):ys)
                        | otherwise = (f1,n1) : merge ((f,n):xs) ys


first :: Polinomio -> Polinomio
first a = take (div (length a) 2) a

second:: Polinomio -> Polinomio
second a = drop (div (length a)  2) a

ordena :: Polinomio -> Polinomio
ordena a = merge (first a) (second a)


equiv :: Polinomio -> Polinomio -> Bool
equiv a b = normalizar a == normalizar b