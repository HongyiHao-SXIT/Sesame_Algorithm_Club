package Project_15;

// 电话卡类（PhoneCard）
class PhoneCards {
    private String phoneNumber;
    protected double balance;

    public PhoneCards(String phoneNumber) {
        this.phoneNumber = phoneNumber;
        this.balance = 0.0;
    }

    public void addBalance(double amount) {
        balance += amount;
        System.out.println("Added " + amount + " to phone card balance. New balance: " + balance);
    }

    public void makeCall(int minutes) {
        double callCost = minutes * 0.1;
        if (balance >= callCost) {
            balance -= callCost;
            System.out.println("Made a call for " + minutes + " minutes. Remaining balance: " + balance);
        } else {
            System.out.println("Insufficient balance to make the call.");
        }
    }

    public double getBalance() {
        return balance;
    }
}

// 主类
public class PhoneCard {
    public static void main(String[] args) {
        // 使用电话卡类
        PhoneCard card = new PhoneCards("1234567890");
        card.addBalance(20.0);
        card.makeCall(30);

        double currentBalance = card.getBalance();
        System.out.println("Current balance: " + currentBalance);
    }
}