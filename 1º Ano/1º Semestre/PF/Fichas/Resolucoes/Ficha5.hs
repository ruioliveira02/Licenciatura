module Ficha5 where


any' :: (a -> Bool) -> [a] -> Bool
any' _ [] = False
any' f (x:xs)   | f x       = True
                | otherwise = any' f xs


zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (a:as) (b:bs) = (f a b) : (zipWith' f as bs)


takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x:xs) | f x       = x : takeWhile' f xs
                    | otherwise = []


dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' f (x:xs) | f x       = dropWhile' f xs
                    | otherwise = (x:xs)


span' :: (a -> Bool) -> [a] -> ([a], [a])
span' _ [] = ([], [])
span' f (x:xs) | f x       = (x : a, b)
               | otherwise = ([], x : xs)
               where (a,b) = span' f xs



deleteBy :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy _ _ [] = []
deleteBy f a (x:xs) | f x a     = xs
                    | otherwise = x : deleteBy f a xs


sortOn :: Ord b => (a -> b) -> [a] -> [a]
sortOn _ [] = []
sortOn f (x:xs) = (sortOn f [y | y <-xs, (f y) < (f x)]) ++ [x] ++ (sortOn f [y | y <- xs, (f y) > (f x)])


type Polinomio = [Monomio]
type Monomio = (Float,Int)

selgrau :: Int -> Polinomio -> Polinomio
selgrau n p = filter (\x -> (snd x) == n) p


conta :: Int -> Polinomio -> Int
conta n p = length $ filter (\x -> (snd x) == n) p


grau :: Polinomio -> Int
grau p = snd $ foldr (\x y-> (0,max (snd x) (snd y))) (-1,-1) p


deriv :: Polinomio -> Polinomio
deriv p = map (derivMonomio) p


derivMonomio :: Monomio -> Monomio
derivMonomio (f, i) | i == 0    = (0,0)
                    | otherwise = (f * fromIntegral i, i - 1)


calcula :: Polinomio -> Float -> Float
calcula p f = foldr (\x h-> calculaMonomio f x + h) 0 p


calculaMonomio :: Float -> Monomio -> Float
calculaMonomio x (f, i) = f * x ^ i 


simp :: Polinomio -> Polinomio
simp p = filter (\x -> fst x /= 0) p


mult :: Monomio -> Polinomio -> Polinomio
mult m p = map (\x -> juntar m x) p


juntar :: Monomio -> Monomio -> Monomio
juntar (f1,n1) (f2,n2) = (f1 * f2, n1 + n2)


ordena :: Polinomio -> Polinomio
ordena [] = []
ordena ((f,n):t) = (ordena (filter (\x -> (snd x) <= n) t)) ++ [(f,n)] ++ (ordena (filter (\x -> (snd x) > n) t))


normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza (p:ps) = (somarMonomios a (0,0)) : normaliza b 
                where (a,b) = (filter (\x -> snd x == snd p) (p:ps), filter (\x -> snd x /= snd p) (p:ps))



somarMonomios :: Polinomio -> Monomio -> Monomio
somarMonomios [] a = a
somarMonomios ((f,n):t) (f1,n1) = somarMonomios t (f + f1, n)



soma :: Polinomio -> Polinomio -> Polinomio
soma a [] = a
soma [] a = a
soma (p:ps) a = (somarMonomios (filter (\x -> snd x == snd p) a) p) : soma ps (filter (\x -> snd x /= snd p) a)


produto :: Polinomio -> Polinomio -> Polinomio
produto [] p = []
produto (m:ms) p = soma (produto ms p) (produtoMonomio m p)

produtoMonomio :: Monomio -> Polinomio -> Polinomio
produtoMonomio (f1,n1) [] = []
produtoMonomio (f1,n1) ((f2,n2):t) = (f1 * f2, n1 + n2) : produtoMonomio (f1, n1) t





type Mat a = [[a]]


dimOK :: Mat a -> Bool
dimOK [] = True
dimOK (l:ls) = dimOk' (length l) ls


dimOK' :: Int -> [a]-> Bool
dimOK' _ [] = True
dimOk' n (p:ps) = and (map (\l -> length l == n) (p:ps))


dimMat :: Mat a -> (Int, Int)
dimMat (a:as) = (length (map (length) (a:as)), length a)



addMat :: Num a => Mat a -> Mat a -> Mat a
addMat (a:as) (b:bs) = zipWith (+) a b : (addMat as bs)
addMat _ _ = []


transposta :: Mat a -> Mat a
transposta [] = []
transposta a = (map head a) : transposta (otherColumns a)


otherColumns :: Mat a -> Mat a
otherColumns m | length (head m) == 1 = []
               | otherwise            = map tail m




multMat :: Num a => Mat a -> Mat a -> Mat a
multMat [] b = []
multMat (a:as) b = let m = transposta b
              in multLinha a b : multMat as b


multLinha :: Num a => [a] -> Mat a -> [a]
multLinha _ [] = []
multLinha l (h:t) = sum (zipWith (*) l h) : multLinha l t



zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c
zipWMat f [] _ = []
zipWMat f _ [] = []
zipWMat f a b = zipWith f (head a) (head b) : zipWMat f (tail a) (tail b)


triSup :: (Num a, Eq a) => Mat a -> Bool
triSup a = triSup' (1,1) a

triSup' ::  (Num a, Eq a) => (Int, Int) -> Mat a -> Bool
triSup' _ [] = True
triSup' (i, j) ([]:t) = triSup' (i + 1, 1) t
triSup' (i,j) ((a:as):t) | i > j     = a == 0 && r
                         | otherwise = r
                where r = triSup' (i, j + 1) (as:t)


rotateLeft :: Mat a -> Mat a
rotateLeft a = transposta (map reverse a)