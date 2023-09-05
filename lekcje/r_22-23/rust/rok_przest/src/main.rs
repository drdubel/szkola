use std::io;

fn czy_przest(rok: i32) {
    if rok % 100 == 0 && rok % 400 == 0 || rok % 4 == 0 && rok % 100 != 0 {
        println!("TAK");
    } else {
        println!("NIE")
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let rok: i32 = input.trim().parse().unwrap();
    czy_przest(rok);
}
