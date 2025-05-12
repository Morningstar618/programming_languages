struct Rect<T> {
    x: T,
    y: T
}

impl<T: std::ops::Mul> Rect<T>
where T: std::ops::Mul<Output = T> + Copy, 
{
    fn area(&self) -> T {
        self.x * self.y
    }
}

fn main() {
    let int_rect = Rect{x: 2, y: 3};
    let float_rect = Rect{x: 1.1, y: 2.3};

    println!("Area int rectangle: {}", int_rect.area());
    println!("Area float rectangle: {}", float_rect.area());
}
