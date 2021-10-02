module Ficha8 where


data Frac = F Integer Integer


normaliza :: Frac -> Frac
normaliza (F num den) = F (num `div` x) (den `div` x)
                      where x = gcd num den


areSameFrac :: Frac -> Frac -> Bool
areSameFrac x y = n1 == n2 && d1 == d2
                where (F n1 d1) = normaliza x
                      (F n2 d2) = normaliza y

instance Eq Frac where
    (==) = areSameFrac




compareFrac :: Frac -> Frac -> Ordering
compareFrac (F n1 d1) (F n2 d2) | (n1 * d2) > (n2 * d1) = GT
                                | (n1 * d2) < (n2 * d1) = LT
                                | otherwise             = EQ

instance Ord Frac where
    compare = compareFrac



showFrac :: Frac -> String
showFrac (F n d) = (show n) ++ "/" ++ (show d)

instance Show Frac where
    show = showFrac



sumFrac :: Frac -> Frac -> Frac
sumFrac (F n1 d1) (F n2 d2) =  normaliza (F (n1*d2 + n2*d1) (d1*d2))

subFrac :: Frac -> Frac -> Frac
subFrac (F n1 d1) (F n2 d2) = normaliza (F (n1*d2 - n2*d1) (d1*d2))

multFrac :: Frac -> Frac -> Frac
multFrac (F n1 d1) (F n2 d2) = normaliza (F (n1 * n2) (d1 * d2))

negFrac :: Frac -> Frac
negFrac (F n1 d1) = (F (-n1) d1)


positive :: Frac -> Bool
positive (F n d) = (n < 0 && d < 0) || (n > 0 && d > 0)


absFrac :: Frac -> Frac
absFrac (F n d) = (F (abs n) (abs d))


signumFrac :: Frac -> Frac
signumFrac (F n d) | positive (F n d) = (F 1 1)
                   | n == 0           = (F 0 1)
                   | otherwise        = (F (-1) 1)

fromIntegerFrac :: Integer -> Frac
fromIntegerFrac x = (F x 1)

instance Num Frac where
    (+) = sumFrac
    (*) = multFrac
    (-) = subFrac
    negate = negFrac
    abs = absFrac
    signum = signumFrac
    fromInteger = fromIntegerFrac



selecionarMaiorDobro :: Frac -> [Frac] -> [Frac]
selecionarMaiorDobro f lst = filter (> 2 * f) lst












data Exp a = Const a
           | Simetrico (Exp a)
           | Mais (Exp a) (Exp a)
           | Menos (Exp a) (Exp a)
           | Mult (Exp a)  (Exp a)



calcula :: (Num a, Show a, Eq a) => Exp a -> a
calcula (Const x)     = x
calcula (Simetrico x) = -1 * calcula x
calcula (Mais l r)    = calcula l + calcula r
calcula (Menos l r)   = calcula l - calcula r
calcula (Mult l r)    = calcula l * calcula r




infixa :: (Num a,Show a, Eq a) => Exp a -> String
infixa (Const x)     = (show x)
infixa (Simetrico x) = "(-" ++ (infixa x) ++ ")"
infixa (Mais l r)    = "(" ++ (infixa l) ++ " + " ++ (infixa r) ++ ")"
infixa (Menos l r)   = "(" ++ (infixa l) ++ " - " ++ (infixa r) ++ ")"
infixa (Mult l r)    = "(" ++ (infixa l) ++ " * " ++ (infixa r) ++ ")"

instance (Num a, Show a, Eq a) => Show (Exp a) where
    show = infixa



areEqualExp :: (Num a, Show a, Eq a) => Exp a -> Exp a -> Bool
areEqualExp a b = (calcula a) == (calcula b)

instance (Num a, Show a, Eq a) => Eq (Exp a) where
    (==) = areEqualExp




sumExp :: (Num a, Show a, Eq a) => Exp a -> Exp a -> Exp a
sumExp a b = Mais a b


subExp :: (Num a, Show a, Eq a) => Exp a -> Exp a -> Exp a
subExp a b = Menos a b

multExp :: (Num a, Show a, Eq a) => Exp a -> Exp a -> Exp a
multExp a b = Mult a b

negExp :: (Num a, Show a, Eq a) => Exp a -> Exp a
negExp a = Simetrico a

absExp :: (Num a, Show a, Eq a) => Exp a -> Exp a
absExp a = Const (abs $ calcula a)



signumExp :: (Num a, Show a, Eq a) => Exp a -> Exp a
signumExp a = Const (signum (calcula a))



fromIntegerExp :: (Num a, Show a, Eq a) => Integer -> Exp a
fromIntegerExp a = Const (fromInteger a)


instance (Num a, Show a, Eq a) => Num (Exp a) where
    (+)         = sumExp
    (-)         = subExp
    (*)         = multExp
    negate      = negExp
    abs         = absExp
    signum      = signumExp
    fromInteger = fromIntegerExp



data Movimento = Credito Float 
               | Debito Float

data Data = D Int Int Int
            deriving Eq

data Extracto = Ext Float [(Data, String, Movimento)]



compareData :: Data -> Data -> Ordering
compareData (D d1 m1 a1) (D d2 m2 a2) | (a1 > a2 || (a1 == a2 && m1 > m2) || (a1==a2 && m1 == m2 && d1 > d2)) = GT
                                      | (a1 < a2 || (a1 == a2 && m1 < m2) || (a1==a2 && m1 == m2 && d1 < d2)) = LT
                                      | otherwise                                                             = EQ


instance Ord Data where
    compare = compareData



showData :: Data -> String
showData (D d m a) = (show a) ++ "/" ++ (show m) ++ "/" ++ (show d)

instance Show Data where
    show = showData




ordena ::  Extracto -> Extracto
ordena (Ext a (x@((D dx mx ax), _,_):xs)) = Ext a  ([y | y@((D d m a),_,_) <- xs, d < dx] ++ [x] ++ [y | y@((D d m a),_,_) <- xs, d > dx])


saldo :: Extracto -> Float
saldo (Ext s [])                   = s
saldo (Ext s ((d,m,Credito c):xs)) = saldo (Ext (s-c) xs)
saldo (Ext s ((d,m,Debito c):xs))  = saldo (Ext (s-c) xs)



normalizeStringsAux :: Int -> [String] -> [String]
normalizeStringsAux x lst = map (\y -> y ++ (take (x - (length y)) (repeat ' '))) lst

normalizeStrings :: [String] -> [String]
normalizeStrings lst = normalizeStringsAux x lst
                     where x = (maximum (map length lst))

showList' :: [(Data, String, Movimento)] -> ([String],[String],[String],[String])
showList' [] = ([], [], [], [])
showList' ((d, str, Credito f):t) = ((show d):a, str:b, (show f):c, "":e) 
                                  where (a,b,c,e) = showList' t
showList' ((d, str, Debito f):t) = ((show d):a, str : b, "":c, (show f):e)
                                 where (a,b,c,e) = showList' t

showTable :: [(Data, String, Movimento)] -> ([String], [String], [String], [String])
showTable t = (a,b,c,d)
            where (a1,b1,c1,d1) = showList' t
                  (a, b, c, d)  = (normalizeStrings ("Data" : a1), normalizeStrings ("Descricao" : b1), normalizeStrings ("Credito" : c1), normalizeStrings ("Debito" : d1))


joinStrings :: ([String], [String], [String], [String]) -> [String]
joinStrings ([], [], [], [])         = []
joinStrings (a:as, b:bs, c:cs, d:ds) = (a ++ " " ++ b ++ " "++ c ++ " " ++ d) : joinStrings (as, bs, cs, ds)
joinStrings _ = []

showExtract :: [(Data, String, Movimento)] -> [String]
showExtract ext = [first] ++ [sep] ++ (joinStrings (as,bs,cs,ds)) ++ [sep]
                where (a:as,b:bs,c:cs,d:ds) = showTable ext
                      first                 = (a ++ " " ++ b  ++ " " ++ c ++ " " ++ d)
                      sep                   = (take (length first) (repeat '-'))

showExtracto :: Extracto -> String
showExtracto (Ext a lst) = ("Saldo anterior: " ++ (show a)) ++ "\n" ++ (unlines $ showExtract lst) ++ ("Saldo atual: " ++ (show (saldo (Ext a lst))))

instance Show Extracto where
    show = showExtracto



extrato = Ext 69420 [(D 23 10 2019, "Compras", Credito 100), (D 23 11 2019, "Compras 2", Debito 20)]
lista = [(D 23 10 2019, "Compras", Credito 100), (D 23 11 2019, "Compras 2", Debito 20)]