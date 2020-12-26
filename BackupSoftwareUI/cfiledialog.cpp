/***********CFileDialog.cpp**********/

#include "cfiledialog.h"
#include <QListView>
#include <QTreeView>
#include <QDialogButtonBox>

CFileDialog::CFileDialog(QWidget *parent)
    : QFileDialog(parent)
{
    this->setOption(QFileDialog::DontUseNativeDialog,true);//不用本地的默认选择框

    //支持多选
    QListView *pListView = this->findChild<QListView*>("listView");//找出名称为listView的所有属于QListView类型的元素
    if (pListView)
        /***
         * When the user selects an item in the usual way, the selection is cleared and the new item selected.
         * However, if the user presses the Ctrl key when clicking on an item, the clicked item gets toggled and all other items are left untouched.
         * If the user presses the Shift key while clicking on an item, all items between the current item and the clicked item are selected or unselected,
         * depending on the state of the clicked item. Multiple items can be selected by dragging the mouse over them.
         ***/
        pListView->setSelectionMode(QAbstractItemView::ExtendedSelection);//支持多选
    QTreeView *pTreeView = this->findChild<QTreeView*>(); //以树状结构展示路径
    if (pTreeView)
        pTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    QDialogButtonBox *pButton = this->findChild<QDialogButtonBox *>("buttonBox");

    disconnect(pButton, SIGNAL(accepted()), this, SLOT(accept()));//使链接失效
    connect(pButton, SIGNAL(accepted()), this, SLOT(onChoise()));//改成自己的槽，如果不改的话，会直接打开对应的文件。


}

CFileDialog::~CFileDialog()
{

}

void CFileDialog::onChoise()
{
    QDialog::accept();
}
