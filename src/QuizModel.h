﻿#ifndef QUIZMODEL_H
#define QUIZMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

#include "QuizItem.h"

constexpr int COLS = 3;

class QuizModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    /* Table model methods */
    QuizModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRow(int row, const QModelIndex &parent = QModelIndex());
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /* Custom methods */
    QuizItem quizItemAt(const int &row) const;
    QuizItem quizItemAt(const QModelIndex &index) const;
    const QVector<QString> &categoryList() const;
    const QVector<QString> &difficultyList() const;
    int numberOfCategories();
    int numberOfDifficulties();
    int quizItemCount(int category, int difficulty);
    int maxQuestionsPerCategory();

signals:
    void quizDataChanged(int category, int difficulty);

private:
    enum class ColumnNames { Category, Difficulty, Question };

    QVector<QuizItem> m_data;
    const QVector<QString> m_categoryList { "Wissenschaft", "Kultur", "Religion", "Erdkunde", "Zeitgeschehen", "Allgemein" };
    const QVector<QString> m_difficultyList { "Easy", "Medium", "Hard", "Extreme" };
    const QVector<int> m_maxQuestionsPerDifficulty { 3, 3, 3, 1};
};

#endif // QUIZMODEL_H
