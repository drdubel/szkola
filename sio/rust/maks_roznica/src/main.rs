use std::io;


fn maks_roznica(mut liczby:Vec<i32>, ilosc_liczb:usize) {
    liczby.sort();
    let roznica = liczby[ilosc_liczb - 1] - liczby[0];
    println!("{}", roznica);
}


fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let ilosc_liczb: usize = input.trim().parse().unwrap();
    input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut liczby: Vec<i32>= Vec::new();
    for liczba in input.split_whitespace() {
        let liczba: i32 = liczba.trim().parse().unwrap();
        liczby.push(liczba);
    }
    maks_roznica(liczby, ilosc_liczb);
}
