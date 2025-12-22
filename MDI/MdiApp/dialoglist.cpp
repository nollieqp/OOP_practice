#include "DialogList.h"
#include "ui_DialogList.h"
#include "SqliteDBManager.h"

DialogList::DialogList(QString dbTableName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);

    // Ініціалізація моделі
    QSqlDatabase db = SqliteDBManager::getInstance()->getDB();
    model = new QSqlTableModel(this, db);
    model->setTable(dbTableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit); // Тільки читання
    model->select(); // Завантажити дані

    // Прив'язка моделі до таблиці
    ui->tableView->setModel(model);

    // Налаштування заголовків (опціонально)
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Назва");
    // Інші колонки підтягнуться автоматично

    // Розтягнути колонки
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void DialogList::refresh() {
    model->select(); // Оновити дані з БД
}

DialogList::~DialogList()
{
    delete ui;
}
