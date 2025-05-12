/*      ------------- CLOSURES -------------
Closures are similar to anonymous functions in javascript and lambda functions in python. The below
function is a closure. Understanding closures is important in rust. The closure signature and the
trait signature are two separate components of the whole closure definition.

The closure signature determines what is being passed into the closure and what is being returned
from it, whilst the trait signature determines the kind of argument that will be passed to the then
implemented anonymous function.

Also, to make a Type: T as a closure, we need to implement one of the `Fn`, `FnMut` or `FnOnce`
trait bound.
    - Fn -> Use this if you wish to call your anonymous function more than once.
    - FnOnce -> Use this if you wish to call it only once.

Closure 1:
    - Closure definition -> 'fn closure_one<T>(f: T)'
      This definition really just means that we are passing an argument 'f' of type 'T'.
    - Trait definition -> 'where T: FnOnce(&str)'
      This means that the type 'T' implements the 'FnOnce' trait that thereby converts this function
      into a closure.
    In the main function, inside 'closure_one', the argument 'x' is received from the closure,
    specifically from the line 'f("closure one")'. This means that whatever anonymous function we
    plan to implement will receive the string literal '"closure one"' as its argument. 'f' here is
    calling the anonymous function itself.

Closure 2:
    - Closure definition - one minor change is that the closure is returning a String.
    - Trait definition - also a minor change here is that the anonymous function is returning a
      String which is then being returned by the closure.

Think of the workflow when calling a closure as: closure -> anon_func, anon_func returns, closure
returns.

 */

fn closure_one<T>(f: T) where T: FnOnce(&str) {
    f("closure one");
}

fn closure_two<T>(f: T) -> String
where T: FnOnce(&i32) -> String {
    let res = f(&2);
    res
}

fn main() {
    let s = "Content passed from closure: ";
    closure_one(|x| {
        println!("{} {}", s, x);
    });

    let result = closure_two(|x | {
        println!("{} {}", s, x);
        String::from("Ayush")
    });

    println!("Content returned from closure 2: {}", result);
}