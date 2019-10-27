#include <iostream>
#include <fstream>
#include <algorithm>

bool compare(std::pair<long, long> const &i1, std::pair<long, long> const &i2)
{
  return ((long double)i1.first / i1.second > (long double)i2.first / i2.second);
}

std::pair<long, long> solve_greedy(long n, long W, long Vn[], long Wn[])
{
  std::pair<long, long> sorted[n];
  for (long i = 0; i < n; i++)
    sorted[i] = std::make_pair(Vn[i], Wn[i]);

  std::sort(sorted, sorted + n, compare);

  long days = 0, pts = 0, cash = W;
  for (long i = 0; i < n && cash > 0; i++)
  {
    long val = sorted[i].first, cost = sorted[i].second;

    if (cost <= cash)
    {
      days += cash / cost;
      pts += val * (cash / cost);
      cash %= cost;
    }
  }

  return std::make_pair(pts, days);
}

std::pair<long, long> solve_dp(long n, long W, long Vn[], long Wn[])
{

  std::pair<long, long> opt[W + 1] = {std::make_pair(0, 0)};

  for (long i = 0; i < n; i++)
    for (long j = W; j >= Wn[i]; j--)
      if (Vn[i] + opt[j - Wn[i]].first >= opt[j].first)
        opt[j] = std::make_pair(Vn[i] + opt[j - Wn[i]].first, opt[j - Wn[i]].second + 1);
      else
        opt[j] = std::make_pair(opt[j].first, opt[j].second);

  return opt[W];
}

int main(int argc, char **argv)
{
  if (argc < 2)
    return 0;

  long available_cash;
  long qtd_islands;

  std::ifstream file;
  file.open(argv[1]);

  file >> available_cash >> qtd_islands;

  long costs[qtd_islands];
  long points[qtd_islands];
  for (long i = 0; i < qtd_islands; i++)
    file >> costs[i] >> points[i];

  file.close();

  std::pair<long, long> res_greedy = solve_greedy(qtd_islands, available_cash, points, costs);
  std::cout << res_greedy.first << " " << res_greedy.second << std::endl;

  std::pair<long, long> res_dp = solve_dp(qtd_islands, available_cash, points, costs);
  std::cout << res_dp.first << " " << res_dp.second << std::endl;

  return 0;
}
