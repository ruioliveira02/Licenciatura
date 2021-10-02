module Teste1819 where


import Data.Char

import System.Random



elemIndices' ::  Eq a => a -> [a] -> [Int]
elemIndices' _ [] = []
elemIndices' a (h:t) | a == h    = 0 : newList
                     | otherwise = newList
                     where newList = map (+1) (elemIndices' a t)



isSubsequenceOf' :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf' [] _ = True
isSubsequenceOf' _ [] = False
isSubsequenceOf' (x:xs) (y:ys) | x == y    = isSubsequenceOf' xs ys
                               | otherwise = isSubsequenceOf' (x:xs) ys






data BTree a = Empty | Node a (BTree a) (BTree a)


lookupAP :: Ord a => a -> BTree (a,b) -> Maybe b
lookupAP _ Empty = Nothing
lookupAP x (Node (a,b) l r) | x == a    = (Just b)
                            | x < a     = lookupAP x l
                            | otherwise = lookupAP x r


zipWithBT :: (a->b->c) -> BTree a -> BTree b -> BTree c
zipWithBT _ Empty _ = Empty
zipWithBT _ _ Empty = Empty
zipWithBT f (Node a l r) (Node b l' r') = Node (f a b) (zipWithBT f l l') (zipWithBT f r r')







digitAlpha :: String -> (String, String)
digitAlpha "" = ("","")
digitAlpha (h:t) | isDigit h = (h:a,b)
                 | isAlpha h = (a,h:b)
                 | otherwise = (a,b)
                 where (a,b) = digitAlpha t





data Seq a = Nil | Cons a (Seq a) | App (Seq a) (Seq a)


firstSeq :: Seq a -> a
firstSeq (Cons a _) = a
firstSeq (App l r)  = firstSeq l



lengthSeq :: Seq a -> Int
lengthSeq Nil = 0
lengthSeq (Cons _ s) = 1 + lengthSeq s
lengthSeq (App a b)  = (lengthSeq a) + (lengthSeq b)


dropSeq :: Int -> Seq a -> Seq a
dropSeq 0 seq = seq
dropSeq n (Cons _ s) = dropSeq (n - 1) s
dropSeq n (App l r) | len < n   = App Nil (dropSeq (n - len) r)
                    | len == n  = App Nil r
                    | otherwise = App (dropSeq n l) r
                    where len = lengthSeq l



instance (Show a) => Show (Seq a) where
    show = showSeq


showSeq :: Show a => Seq a -> String
showSeq seq = "<<" ++ (tail $ init str) ++ ">>"
            where str = show (seqToList seq)


seqToList :: Seq a -> [a]
seqToList Nil = []
seqToList (Cons a seq) = a : (seqToList seq)
seqToList (App l r) = (seqToList l) ++ (seqToList r)



type Mat a = [[a]]


getElem :: Mat a -> IO a
getElem mat = do
            let w = length (head mat)
                h = length mat
            i <- randomRIO (0,(h - 1))
            j <- randomRIO (0,(w - 1))
            

            return ((mat !! i) !! j)




magic :: Mat Int -> Bool
magic mat = (length finalList) == 0
          where finalList = filter (/= h) list
                h         = head list
                list      = rows ++ cols ++ diag
                rows      = map sum mat
                cols      = map sum (getCols mat)
                diag      = map sum (getDiag mat)


getCols :: Mat a -> [[a]]
getCols ([]:_) = []
getCols mat = (map head mat) : (getCols (map tail' mat))



getDiag :: Mat a -> [[a]]
getDiag [[]] = []
getDiag mat = [getDiag' mat, getDiag' (map reverse mat)]



getDiag' :: Mat a -> [a]
getDiag' [] = []
getDiag' mat = (head (head mat)) : getDiag' (map tail' (tail' mat))


tail' [] = []
tail' (x:t) = t