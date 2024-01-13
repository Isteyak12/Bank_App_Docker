from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

# Sample data for accounts
accounts = {
    '1': {'name': 'Alice', 'balance': 1000},
    '2': {'name': 'Bob', 'balance': 1500},
    '3': {'name': 'Charlie', 'balance': 1200},
}

@app.route('/')
def home():
    return render_template('index.html', accounts=accounts)

@app.route('/account/<account_id>')
def account(account_id):
    account_info = accounts.get(account_id)
    if account_info:
        return render_template('account.html', account_info=account_info)
    else:
        return 'Account not found', 404

@app.route('/transfer', methods=['POST'])
def transfer():
    sender_id = request.form.get('sender')
    recipient_id = request.form.get('recipient')
    amount = int(request.form.get('amount'))

    sender = accounts.get(sender_id)
    recipient = accounts.get(recipient_id)

    if sender and recipient and sender['balance'] >= amount:
        sender['balance'] -= amount
        recipient['balance'] += amount
        return redirect(url_for('home'))
    else:
        return 'Transfer failed. Check account IDs and balance.', 400

if __name__ == '__main__':
    app.run(debug=True)
