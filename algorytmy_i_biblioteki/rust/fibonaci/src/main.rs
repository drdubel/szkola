use num_bigint::BigUint;
use num_traits::One;
use std::io;


fn fib(ktora_liczba: usize) -> BigUint
{
    let mut liczba1: BigUint = One::one();
    let mut liczba2: BigUint = One::one();
    for _ in 0..ktora_liczba {
        let suma = liczba1 + &liczba2;
        liczba1 = liczba2;
        liczba2 = suma;
    }
    liczba1
}


fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let ktora_liczba: usize = input.trim().parse().unwrap();
    println!("{} liczba fibonacciego to {}", ktora_liczba, fib(ktora_liczba));
}
