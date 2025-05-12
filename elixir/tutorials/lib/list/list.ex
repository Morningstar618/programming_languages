defmodule Tutorials.List do
  @moduledoc """
  1. sum -> uses normal recursion i.e. neither head nor tail
  2. sum_tail -> uses tail recursion
  """

  @spec sum([number()]) :: number()
  @doc """
  returns the sum of numbers in a list
  """
  def sum([]), do: 0
  def sum([h | t]), do: h + sum(t)

  @spec sum_tail([number()]) :: any()
  @doc """
  returns the sum of numbers in a list
  """
  def sum_tail(nums, acc \\ 0)
  def sum_tail([], acc), do: acc

  def sum_tail([h | t], acc), do: sum_tail(t, acc + h)


  # ---------------------Reverse---------------------------

  @spec reverse([any()], [any()]) :: list(any())
  @doc """
  reverses a provided list in O(n)
  """
  def reverse(elements, acc \\ [])
  def reverse([], acc), do: acc

  def reverse([h | t], acc), do: reverse(t, [h | acc])


  # ------------------------Map-----------------------------

  @spec map([any()], (any() -> any()), [any()]) :: [any()]
  def map(elements, func, acc \\ [])
  def map([], _, acc), do: acc |> reverse #ignore value of fn fun in our base case

  def map([h | t], func, acc), do: map(t, func, [func.(h) | acc])


  # ------------------------Concat-----------------------------

  @spec concat([any()], [any()]) :: [any()]
  @doc """
  Adds two lists together
  """
  def concat(src, dst), do: concat_func(src |> reverse, dst)

  defp concat_func([], dst), do: dst
  defp concat_func([h | t], dst), do: concat_func(t, [h | dst])


  # ----------------------Flat Map------------------------------

  @spec flat_map(list(), any()) :: any()
  def flat_map(elements, func, acc \\ [])
  def flat_map([], _, acc), do: acc

  def flat_map([h | t], func, acc), do: flat_map(t, func, concat(acc, func.(h)))

end
