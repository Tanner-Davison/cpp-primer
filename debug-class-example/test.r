# Load required libraries
library(tidyverse)
library(ggplot2)

# Create sample data
set.seed(123)
sales_data <- data.frame(
  date = seq(as.Date("2024-01-01"), as.Date("2024-12-31"), by = "day"),
  sales = rnorm(366, mean = 1000, sd = 200),
  category = sample(c("Electronics", "Clothing", "Food"), 366, replace = TRUE)
)

# Basic data manipulation
monthly_sales <- sales_data %>%
  mutate(month = format(date, "%Y-%m")) %>%
  group_by(month, category) %>%
  summarize(
    total_sales = sum(sales),
    avg_sales = mean(sales),
    sd_sales = sd(sales)
  ) %>%
  arrange(desc(total_sales))

# Create a visualization
ggplot(monthly_sales, aes(x = month, y = total_sales, fill = category)) +
  geom_bar(stat = "identity", position = "dodge") +
  theme_minimal() +
  labs(
    title = "Monthly Sales by Category",
    x = "Month",
    y = "Total Sales",
    fill = "Product Category"
  ) +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))

# Basic statistical analysis
sales_summary <- sales_data %>%
  group_by(category) %>%
  summarize(
    count = n(),
    mean_sales = mean(sales),
    median_sales = median(sales),
    min_sales = min(sales),
    max_sales = max(sales)
  )

# Print results
print(sales_summary)

# Perform a simple t-test
electronics_sales <- sales_data %>%
  filter(category == "Electronics") %>%
  pull(sales)

clothing_sales <- sales_data %>%
  filter(category == "Clothing") %>%
  pull(sales)

t.test(electronics_sales, clothing_sales)
