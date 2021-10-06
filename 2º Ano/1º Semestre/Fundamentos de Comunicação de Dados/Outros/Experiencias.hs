module Experiencias where

import qualified Data.List as DL

insert :: Ord a => a -> [a] -> [a]
insert a []     = [a]
insert a (x:xs) | a > x     = (a:x:xs)
                | otherwise = x : (insert a xs)

sort :: Ord a => [a] -> [a]
sort [] = []
sort (x:xs) = insert x (sort xs)


partition :: Int -> Double -> Double -> [Double] -> Double
partition (0) cur total _ = abs (total / 2 - cur)
partition n cur total (x:xs) = partition (n - 1) (cur + x) total xs


minimum' :: Ord a => [a] -> (a, Int)
minimum' [a]    = (a, 0)
minimum' (x:xs) | a < x     = (a,i + 1)
                | otherwise = (x,0)
                where (a,i) = minimum' xs



divideSet :: [Double] -> ([Double], [Double])
divideSet list = splitAt (index + 1) list
               where (_,index) = minimum' (map (\x -> partition x 0 s list) [1..(n-1)])
                     n         = length list
                     s         = sum list



generateCode :: [Double] -> [[Int]]
generateCode [a]  = [[]]
generateCode list = (map (\x -> 0 : x) a') ++ (map (\x -> 1 : x) b')
                  where (a,b) = divideSet list
                        (a',b') = (generateCode a, generateCode b)



encode :: [Int] -> [[Int]] -> [Int]
encode [] _ = []
encode (x:xs) code = (code !! x) ++ (encode xs code)


elem' :: Eq a => [[a]] -> [a] -> Maybe Int
elem' [] _     = Nothing
elem' (x:xs) a | DL.isPrefixOf x a = Just 0
               | otherwise         = case (elem' xs a) of
                                        Just b  -> Just (b + 1)
                                        Nothing -> Nothing



decode :: [Int] -> [[Int]] -> Maybe [Int]
decode [] _      = Just []
decode list code = case (elem' code list) of 
                        (Just index) -> case (decode (drop (length (code !! index)) list) code) of
                                                Just ls -> Just (index : ls)
                                                Nothing -> Nothing
                        Nothing      -> Nothing