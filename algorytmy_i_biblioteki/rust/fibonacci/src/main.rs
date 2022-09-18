use num_bigint::BigUint;
use num_traits::{Zero, One};
use std::mem::replace;


fn fib(n: usize) -> BigUint
{
    let mut liczba1: BigUint = Zero::zero();
    let mut liczba2: BigUint = One::one();
    for _ in 0..n {
        let f2 = liczba1 + &liczba2;
        liczba1 = replace(&mut liczba2, f2);
    }
    liczba1
}


fn main()
{
    println!("fib 1000 = {}", fib(1000000));
}
