defmodule Tutorials.Structs.Expense do

  alias Tutorials.Structs.Expense

  defstruct(
    title: "",
    date: nil,
    amount: 0,
    store: ""
  )

  @type t :: %Expense{
    title: String.t(),
    date: Date.t() | nil,
    amount: number(),
    store: String.t()
  }

  @spec sample() :: [t()]
  def sample do
    [
      %Expense{title: "Food", date: ~D[2025-01-25], amount: 239, store: "Banaras"},
      %Expense{title: "Food", date: ~D[2024-12-05], amount: 130, store: "Softy"},
      %Expense{title: "Monitor", date: ~D[2022-04-15], amount: 6000, store: "Metro"},
      %Expense{title: "Laptop", date: ~D[2024-10-28], amount: 22000, store: "Amazon"},
      %Expense{title: "Phone", date: ~D[2023-01-22], amount: 33000, store: "Flipkart"}
    ]
  end

  @spec total(any()) :: number()
  def total(expenses) do
    expenses |> Enum.map(
      fn %{amount: amount} ->
        amount
      end
    ) |> Enum.sum()
  end

  @spec sort_by_date(t()) :: [t()]
  def sort_by_date(expenses) do
    expenses |> Enum.sort_by(& &1.date)
  end


  def add_expense(%Expense{} = expense) do
    [expense | sample() ]
  end

  def update_amount(title, amount) do
    [item] = sample() |> Enum.filter(
      fn %{title: title_check} ->
        title_check == title
      end
    )
    new_item = %{item | amount: amount}
    [new_item | sample() |> List.delete(item)]
  end


  #_______________With_______________________

  #login -> authenticate, verify_password
  @users ["Coco", "Cece", "Louis", "Chiko"]

  def authenticate(user) when user in @users, do: {:ok, "authorized"}
  def authenticate(_), do: {:error, "unauthorized"}

  def verify_password(user, _password) when user in @users, do: {:ok, "password verified"}
  def verify_password(_user, _password), do: {:error, "wrong password"}

  def login(user, password) do
    with {:ok, _auth_msg} <- authenticate(user),
    {:ok, _msg} <- verify_password(user, password) do
      {:ok, "User logged in successfully"}
    else
      {:error, msg} -> {:error, msg}
    end
  end


end
