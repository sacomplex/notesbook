using System;
using System.Collections.Generic;

namespace _06_Introduction_to_classes
{
    public class BankAccount
    {
        /// <summary>
        /// 属性元素 : 账号
        /// </summary>
        public string Number { get; }
        /// <summary>
        /// 属性元素 : 拥有者
        /// </summary>
        public string Owner { get; set; }
        /// <summary>
        /// 属性元素 : 账户金额
        /// </summary>
        public decimal Balance {
            get {
                decimal balance = 0;
                foreach (var item in allTransactions)
                {
                    balance += item.Amount;
                }

                return balance;
            }
        }

        private List<Transaction> allTransactions = new List<Transaction>();

        private static int accountNumberSeed = 1234567890;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="name">姓名</param>
        /// <param name="initialBalance">账户初始金额</param>
        public BankAccount(string name, decimal initialBalance)
        {
            this.Number = accountNumberSeed.ToString();
            accountNumberSeed++;

            this.Owner = name;
            MakeDeposit(initialBalance, DateTime.Now, "Initial balance");
        }

        /// <summary>
        /// 方法 : 钱存
        /// </summary>
        /// <param name="amount">金额</param>
        /// <param name="date">日期</param>
        /// <param name="note">记录</param>
        public void MakeDeposit(decimal amount, DateTime date, string note)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(amount), "Amount of deposit must be positive");
            }

            var deposit = new Transaction(amount, date, note);

            allTransactions.Add(deposit);
        }

        /// <summary>
        /// 方法 : 取钱
        /// </summary>
        /// <param name="amount">金额</param>
        /// <param name="date"> 日期 </param>
        /// <param name="note">记录</param>
        public void MakeWithdrawal(decimal amount, DateTime date, string note)
        {
            if (amount <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(amount), "Amount of withdrawal must be positive");
            }

            if (Balance - amount < 0)
            {
                throw new InvalidOperationException("Not sufficient funds for this withdrawal");
            }

            var withdrawal = new Transaction(-amount, date, note);

            allTransactions.Add(withdrawal);
        }

        public string GetAccountHistory()
        {
            var report = new System.Text.StringBuilder();

            report.AppendLine("Date\t\tAmount\tNote");
            foreach (var item in allTransactions)
            {
                report.AppendLine($"{item.Date.ToShortDateString()}\t{item.Amount}\t{item.Notes}");
            }

            return report.ToString();
        }
    }
}