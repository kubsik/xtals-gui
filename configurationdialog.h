#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QTabWidget;
class QComboBox;
class QPushButton;
class QLabel;
class QLineEdit;
//class QTextEdit;
QT_END_NAMESPACE

class ConfigurationDialog : public QDialog
{
    Q_OBJECT
public:
    ConfigurationDialog(QWidget *parent = nullptr);
    QString pathToSaveConfiguration;

public slots:
    void saveConfiguration();

private:
    QWidget *inputDataWidget;
        QLineEdit *images_directory;
        QLineEdit *log_file_path;
        QLineEdit *images_to_skip;
        QComboBox *data_source;
        QComboBox *data_type;
        QLineEdit *lu_input_assigned_dataset_name;
        QString findText;
    QWidget *outputDataWidget;
        QLineEdit *output_directory;
        QLineEdit *images_dataset_name;
        QLineEdit *signal_dataset_name;
        QLineEdit *integrated_dataset_name;
        QLineEdit *simulated_dataset_name;
        QLineEdit *lu_output_expt_dataset_name;
    QWidget *integrationWidget;
        QComboBox *integration_method;
        QLineEdit *trust_level;
        QLineEdit *signal_level;
        QLineEdit *alpha;
        QLineEdit *cutoff_level;
        QLineEdit *kw_block_length;
        QLineEdit *rejected_rectangles;
        QLineEdit *rejected_general_rectangles;
        QLineEdit *rejected_discs;
        QLineEdit *rejected_discs_complement;
        QLineEdit *rejected_border;
        QComboBox *remove_intersected;
        QLineEdit *min_amount_of_pixels;
        QLineEdit *morphological_operations;
        QComboBox *intensity_weighted_centers;
        QComboBox *sum_of_bitmasks;
        QLineEdit *amount_in_block;
        QComboBox *primary_beam_normalisation;
        QComboBox *background_correction;
        QComboBox *verbose_pixel_grid;
        QLineEdit *verbose_pixel_size_n_x;
        QLineEdit *verbose_pixel_size_n_y;
        QLineEdit *verbose_selected_pixel;
        QComboBox *save_bitmasks_as;
    QWidget *geometryWidget;
        QLineEdit *detector_distance;
        QLineEdit *beam_center_x;
        QLineEdit *beam_center_y;
        QLineEdit *pixel_size_x;
        QLineEdit *pixel_size_y;
        QLineEdit *alpha_angle;
        QLineEdit *beta_angle;
        QLineEdit *omega_angle;
        QLineEdit *kappa_angle;
        QLineEdit *detector_distance_initial;
        QLineEdit *beam_center_x_initial;
        QLineEdit *beam_center_y_initial;
        QLineEdit *iter_max;
        QLineEdit *damping_factor;
        QLineEdit *intensity_cutoff;
        QLineEdit *matching_angle;
        QLineEdit *convergence_criteria;
        QComboBox *recalculate_pairs;
//    QWidget *ratiosWidget;
    QWidget *simulationsWidget;
        QLineEdit *sim_lambda_min;
        QLineEdit *sim_lambda_max;
        QLineEdit *sim_sinthl_max;
        QLineEdit *sim_a;
        QLineEdit *sim_b;
        QLineEdit *sim_c;
        QLineEdit *sim_alpha;
        QLineEdit *sim_beta;
        QLineEdit *sim_gamma;
        QLineEdit *sim_detector_distance;
        QLineEdit *sim_detector_width;
        QLineEdit *sim_detector_height;
        QLineEdit *sim_pixel_size_x;
        QLineEdit *sim_pixel_size_y;
        QLineEdit *sim_beam_center_x;
        QLineEdit *sim_beam_center_y;
        QComboBox *sim_running_angle;
        QLineEdit *sim_angle_start;
        QLineEdit *sim_angle_stop;
        QLineEdit *sim_angle_step;
        QLineEdit *sim_omega_angle;
        QLineEdit *sim_chi_angle;
        QLineEdit *sim_phi_angle;
        QLineEdit *sim_u_omega_angle;
        QLineEdit *sim_u_chi_angle;
        QLineEdit *sim_u_phi_angle;
        QComboBox *sim_export_images;
    QWidget *machineWidget;
        QLineEdit *max_host_memory;
        QLineEdit *max_device_memory;
    QTabWidget *configurationTabWidget;
    QPushButton *saveButton;
};

#endif // CONFIGURATIONDIALOG_H
