defmodule Tutorials.Recursion.Factorial do

  def fact(num, acc \\ 1)
  def fact(0, acc), do: acc

  def fact(num, acc), do: fact(num - 1, acc * num)

end
