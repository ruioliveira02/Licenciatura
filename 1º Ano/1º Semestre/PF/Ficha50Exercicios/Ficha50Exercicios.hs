import Data.Char

enumFromTo' :: Int -> Int -> [Int]
enumFromTo' l r | r < l = []
               | otherwise = [l] ++ (enumFromTo' (l + 1) r)


enumFromThenTo' :: Int -> Int -> Int -> [Int]
enumFromThenTo' l a r | r < l = []
                      | otherwise = [l] ++ (enumFromThenTo' (l + a - 1) a r)


(+++) :: [a] -> [a] -> [a]
(+++) [a] [x] = [a,x]
(+++) (a:as) [x] = a : (+++) as [x]
(+++) a (x:xs) = (+++) ((+++) a [x]) xs 

(!!!) :: [a] -> Int -> a
(!!!) a 0 = head a
(!!!) a x = (tail a) !!! (x - 1)

reverse' :: [a] -> [a]
reverse' [] = []
reverse' a = (reverse' (tail a)) ++ [head a]

take' :: Int -> [a] -> [a]
take' 0 a = []
take' _ [] = []
take' a l = [head l] ++ (take' (a - 1) (tail l))

drop' :: Int -> [a] -> [a]
drop' 0 a = a
drop' _ [] = []
drop' x a = drop' (x - 1) (tail a)

zip' :: [a] -> [b] -> [(a, b)]
zip' [] _ = []
zip' _ [] = []
zip' a b = [((head a), (head b))] ++ (zip' (tail a) (tail b))

elem' :: Eq a => a -> [a] -> Bool
elem' _ []  = False
elem' x a | (head a) == x = True
          | otherwise = elem' x (tail a)


replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' x a = [a] ++ replicate' (x - 1) a

intersperse' :: a -> [a] -> [a]
intersperse' x a | length a == 1 = a
                 | otherwise = [head a, x] ++ intersperse' x (tail a)

group' :: Eq a => [a] -> [[a]]
group' [] = [[]]
group' a | x == [[]] = [[head a]]
         | head a == head (head x) = [[head a] ++ (head x)] ++ (tail x)
         | otherwise = [[head a]] ++ x
         where x = group' (tail a)

concat' :: [[a]] -> [a]
concat' [[]] = []
concat' a | length (head a)  == 0 = concat' (tail a)
          | otherwise = [head (head a)] ++ concat'(x)
          where x = [tail (head a)] ++ tail a



safeLast :: [[a]] -> [a]
safeLast [] = []
safeLast a = last a

inits' :: [a] -> [[a]]
inits' [] = [[]]
inits' a = inits' b ++ [a]
    where b = init a

tails' :: [a] -> [[a]]
tails' [] = [[]]
tails' a = [a] ++ tails' (tail a)

isPrefixOf' :: Eq a => [a] -> [a] -> Bool
isPrefixOf' pref list = elem pref $ inits' list


isSuffixOf' :: Eq a => [a] -> [a] -> Bool
isSuffixOf' suf list = elem suf $ tails' list



isSubsequenceOf' :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf' [] _ = True
isSubsequenceOf' _ [] = False
isSubsequenceOf' (s:ys) (x:xs)
                            | s == x    = isSubsequenceOf' ys xs
                            | otherwise = isSubsequenceOf' (s:ys) xs


-- PERGUNTAR SE RESTRICOES DO ENUNCIADO TEM DE SER VERIFICADAS----
------------------------------------------------------------------
elemIndices' :: Eq a => a -> [a] -> [Int]
elemIndices' x a = elemIndices1 x a 0 

elemIndices1 :: Eq a => a -> [a] -> Int -> [Int]
elemIndices1 _ [] _ = []
elemIndices1 a (x:xs) n
                    | x == a    = n : elemIndices1 a xs (n + 1)
                    | otherwise = elemIndices1 a xs (n + 1)



removeAll :: Eq a => [a] -> a -> [a]
removeAll [] _ = []
removeAll (x:xs) a 
                | x == a    = removeAll xs a
                | otherwise = x : removeAll xs a


nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' (x:xs) = x : nub' (removeAll xs x)


delete' :: Eq a => a -> [a] -> [a]
delete' _ [] = []
delete' no (x:xs)
                | x == no   = xs
                | otherwise = x : delete' no xs


(\\) :: Eq a => [a] -> [a] -> [a]
(\\) a [] = a
(\\) a (x:xs) = (\\) (delete' x a) xs

union' :: Eq a => [a] -> [a] -> [a]
union' a [] = a
union' a (x:xs) 
                | elem x a  = union' a xs
                | otherwise = union' a xs ++ [x]





deleteAll :: Eq a => a -> [a] -> [a]
deleteAll _ [] = []
deleteAll no (x:xs)
                | x == no   = deleteAll no xs
                | otherwise = x : deleteAll no xs


intersect' :: Eq a => [a] -> [a] -> [a]
intersect' []  a = []
intersect' (x:xs) a
                | not (elem x a)  = intersect' xs a
                | otherwise = x : intersect' xs a



-- O(N)
insert' :: Ord a => a -> [a] -> [a]
insert' a [] = [a]
insert' a (x:xs)
            | x < a     = x : insert' a xs
            | otherwise = a : (x:xs)

unwords' :: [String] -> String
unwords' [x] = x
unwords' (x:xs) = x ++ " " ++ unwords' xs

unlines' :: [String] -> String
unlines' [] = ""
unlines' (x:xs) = x ++ "\n" ++ unlines xs



encontraMax :: Ord a => [a] -> a
encontraMax [x] = x
encontraMax (x:xs) = max x (encontraMax xs)

pMaiorAux :: Ord a => [a] -> a -> Int -> Int
pMaiorAux (x:xs) maxi i | maxi == x = i
                        | otherwise = pMaiorAux xs maxi (i + 1)

pMaior :: Ord a => [a] -> Int
pMaior (x:xs) = pMaiorAux (x:xs) (encontraMax (x:xs)) 0


temRepetidosAux :: Eq a => [a] -> [a] -> Bool
temRepetidosAux [] _ = False
temRepetidosAux (x:xs) a
                        | elem x a  = True
                        | otherwise = temRepetidosAux xs (x:a)


temRepetidos :: Eq a => [a] -> Bool
temRepetidos a = temRepetidosAux a []


algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (x:xs) 
                | isDigit x = x : algarismos xs
                | otherwise = algarismos xs


posImpares :: [a] -> [a]
posImpares (x:y:t) = y : posImpares (t)
posImpares _ = []


posPares :: [a] -> [a]
posPares (x:y:t) = x : posPares t
posPares [x] = [x]
posPares [] = []


isSorted :: Ord a => [a] -> Bool
isSorted [x] = True
isSorted (x:y:xs)
                | x <= y    = isSorted (y:xs)
                | otherwise = False
                


insert :: Ord a => a -> [a] -> [a]
insert a [] = [a]
insert a (x:xs)
            | a > x     = x : insert a xs
            | otherwise = a : (x:xs)

iSort :: Ord a => [a] -> [a]
iSort [] = []
iSort (x:xs) = insert x (iSort xs)


menor :: String -> String -> Bool
menor _ [] = False
menor [] _ = True
menor (x:xs) (y:ys)
                    | ord x < ord y = True
                    | ord x > ord y = False
                    | otherwise     = menor xs ys


elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet _ [] = False
elemMSet a ((x,y):xs)
                | a == x    = True
                | otherwise = elemMSet a xs


lengthMSetAux :: [(a, Int)] -> Int -> Int
lengthMSetAux [] a = a
lengthMSetAux (x:xs) a = lengthMSetAux xs (a + 1)

lengthMSet :: [(a, Int)] -> Int
lengthMSet a = lengthMSetAux a 0


converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((a,i):t) = (take i (repeat a)) ++ converteMSet t


insereMSet :: Eq a => a -> [(a,Int)] -> [(a, Int)]
insereMSet a [] = [(a, 1)]
insereMSet a ((a1,x):t)
                    | a == a1   = (a, x + 1) : t
                    | otherwise = (a1,x) : insereMSet a t


removeMSet :: Eq a => a -> [(a,Int)] -> [(a, Int)]
removeMSet a [] = []
removeMSet a ((a1,x):t)
                    | a == a1 && x > 1 = (a, x - 1) : t
                    | a == a1         = t
                    | otherwise       = (a1,x) : removeMSet a t



--ORDEM INTERESSA????????????
--Se interessar, modificar insereMSet para introduzir no inicio
constroiMSet :: Ord a => [a] -> [(a, Int)]
constroiMSet [] = []
constroiMSet (x:xs) = insereMSet x (constroiMSet xs)



partitionEithers' :: [Either a b] -> ([a], [b])
partitionEithers' [] = ([], [])
partitionEithers' ((Left a):t) = (a : c, d)
                                   where (c,d) = partitionEithers' t
partitionEithers' ((Right b):t) = (c, b:d)
                                   where (c,d) = partitionEithers' t


catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes (Nothing : t) = catMaybes t
catMaybes ((Just a) : t) = a : catMaybes t



data Movimento = Norte | Sul | Este | Oeste deriving Show

posicao :: (Int, Int) -> [Movimento] -> (Int, Int)
posicao (x,y) [] = (x,y)
posicao (x,y) (x1:xs) = case x1 of
                            Norte -> posicao (x, y + 1) xs
                            Sul -> posicao (x, y - 1) xs
                            Oeste -> posicao (x - 1, y) xs
                            Este -> posicao (x + 1, y) xs



caminho :: (Int, Int) -> (Int, Int) -> [Movimento]
caminho (x1,y1) (x2, y2)
                        | x1 < x2 && y1 < y2   = take (x2 - x1) (repeat Este) ++ take (y2 - y1) (repeat Norte)
                        | x1 < x2 && y1 >= y2  = take (x2 - x1) (repeat Este) ++ take (y1 - y2) (repeat Sul)
                        | x1 >= x2 && y1 < y2  = take (x1 - x2) (repeat Oeste) ++ take (y1 - y2) (repeat Norte)
                        | otherwise            = take (x1 - x2) (repeat Oeste) ++ take (y1 - y2) (repeat Sul)



--COMO REDUZIR O TAMANHO DO CODIGO
vertical :: [Movimento] -> Bool
vertical [] = True
vertical (x:xs) = case x of
                    Oeste -> False
                    Este -> False
                    Norte -> vertical xs
                    Sul -> vertical xs



data Posicao = Pos Int Int deriving Show


mini :: Posicao -> Posicao -> Posicao
mini (Pos x1 y1) (Pos x2 y2)
                | x1^2 + y1^2 < x2^2 + y2^2 = (Pos x1 y1)
                | otherwise                 = (Pos x2 y2)

maisCentral :: [Posicao] -> Posicao
maisCentral [x] = x
maisCentral (x:xs) = mini x (maisCentral xs)

vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos _ [] = []
vizinhos (Pos x1 y1) ((Pos x2 y2):t)
                                    | x1 == x2 && abs (y2 - y1) == 1 = (Pos x2 y2) : next
                                    | y1 == y2 && abs (x2 - x1) == 1 = (Pos x2 y2) : next
                                    | otherwise                      = next
                                    where next = vizinhos (Pos x1 y1) t



mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada [x] = True
mesmaOrdenada ((Pos x1 y1):(Pos x2 y2):t)
                                        | y1 /= y2  = False
                                        | otherwise = mesmaOrdenada ((Pos x2 y2):t)



data Semaforo = Verde | Amarelo | Vermelho deriving Show

intersecaoOKAux :: [Semaforo] -> Int
intersecaoOKAux [] = 0
intersecaoOKAux (Vermelho : xs) = 1 + intersecaoOKAux xs
intersecaoOKAux (x:xs) = intersecaoOKAux xs

intersecaoOK :: [Semaforo] -> Bool
intersecaoOK a = intersecaoOKAux a <= 1
