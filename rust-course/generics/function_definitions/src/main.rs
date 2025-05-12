fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest: &T = &list[0];

    for i in list {
        if i > largest {
            largest = i;
        }
    }

    largest
}

fn main() {
    let number_list = vec![34, 50, 25, 101, 65];
    let char_list = vec!['a', 'y', 'u', 's', 'h'];

    let largest_num = largest(&number_list);
    let largest_char = largest(&char_list);

    println!("largest num : {}", largest_num);
    println!("largest char: {}", largest_char);
}
