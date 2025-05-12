defmodule Tutorials.Structs.SevenWonders do
  defstruct name: "", country: ""
  alias Tutorials.Structs.SevenWonders

  @type t :: %SevenWonders{
    name: String.t(),
    country: String.t()
  }

  #____________________All_______________________________
  @spec all :: [t()]
  def all() do
    [
      %SevenWonders{name: "Taj Mahal", country: "India"},
      %SevenWonders{name: "Chichen Itza", country: "Mexico"},
      %SevenWonders{name: "Petra", country: "Jordan"},
      %SevenWonders{name: "Machu Picchu", country: "Peru"},
      %SevenWonders{name: "Christ the Redeemer", country: "Brazil"},
      %SevenWonders{name: "Colesseum", country: "Italy"},
      %SevenWonders{name: "The Great Wall of China", country: "China"},
    ]
  end

  #____________________Print names____________________________

  def print_names([]), do: :ok

  @spec print_names([t()]) :: :ok
  def print_names(wonders), do: wonders |>
  Enum.each(fn %{name: name} -> IO.puts(name) end)

  @spec filter_by_country([t()], String.t()) :: [t()]
  def filter_by_country(wonders, country) do
    wonders |> Enum.filter(
      fn %{country: country_name} ->
        country_name == country
      end
    )
  end

  @spec in_countries_starting_with_i(any()) :: :ok
  def in_countries_starting_with_i(wonders) do
    wonders |> Enum.each(
      fn wonder ->
        <<first_char::utf8, _::binary>> = wonder.country
        case first_char do
          73 -> IO.inspect(wonder)
          105 -> IO.inspect(wonder)
          _ -> nil
        end
      end
    )
  end<

  @spec sort_country_by_length(any()) :: list()
  def sort_country_by_length(wonders) do
    wonders |> Enum.sort(
      fn x, y ->
        String.length(x.country) < String.length(y.country)
      end
    )
  end

  @spec name_country_list(any()) :: any()
  def name_country_list(wonders) do
    wonders |> Enum.reduce([],
    fn wonder, acc ->
      [[wonder.name, wonder.country] | acc]
    end
    )
  end

  @spec country_name_keyword_list(any()) :: any()
  def country_name_keyword_list(wonders) do
    wonders |> Enum.reduce([],
    fn wonder, acc ->
      [{String.to_atom(wonder.name), wonder.country} | acc]
    end
    )
  end

  @spec all_names(any()) :: list()
  def all_names(wonders) do
    wonders |> Enum.map(
      fn %{name: name} ->
        name
      end
    )
  end

end
