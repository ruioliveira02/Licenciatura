merge :: Ord a => [a] -> [a] -> [a]
merge a [] = a
merge [] a = a
merge (x:xs) (y:ys)
                | x < y     = x : merge xs (y:ys)
                | otherwise = y : merge (x:xs) ys


mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [a] = [a]
mergeSort lista = merge (mergeSort x) (mergeSort y)
                where (x,y) = splitAt (div (length lista) 2) lista



{-

mergeSort :: [Integer] -> Int -> Int -> [Integer]
mergeSort a l r | l < r = let m = div (l + r) 2
                          in (merge (mergeSort a l m) (mergeSort a (m + 1) r))
                | l == r = [last (take l a)]
                | otherwise = []


-}


divideList:: Ord a => a -> [a] -> ([a], [a])
divideList _ [] = ([], []) 
divideList x (y:ys)
                | y < x     = ((y : a), b)
                | otherwise = (a, (y:b))
                where (a,b) = divideList x ys


quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort [a] = [a]
quickSort (x:xs) = (quickSort a) ++ [x] ++ (quickSort b)
                where (a,b) = divideList x xs




insert :: Ord a => a -> [a] -> [a]
insert a [] = [a]
insert a (x:xs)
            | x < a     = x : insert a xs
            | otherwise = a : (x:xs)


insertionSort :: Ord a => [a] -> [a]
insertionSort [] = []
insertionSort (x:xs) = insert x (insertionSort xs)