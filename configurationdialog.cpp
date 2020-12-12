#include <QtWidgets>
#include "toolbox.h"
#include "configurationdialog.h"

ConfigurationDialog::ConfigurationDialog(QWidget *parent):QDialog(parent)
{
    setWindowTitle(tr("Setup configuration"));

    /* InputData page */
    QWidget *inputDataWidget = new QWidget;

    QLabel *imagesDirLabel = new QLabel(tr("images_directory:"));
    images_directory = new QLineEdit;
    images_directory->setText("");

    QLabel *logPathLabel = new QLabel(tr("log_file_path:"));
    log_file_path = new QLineEdit;
    log_file_path->setText("");

//    QLabel *skipImagesLabel = new QLabel(tr("images_to_skip:"));
//    images_to_skip = new QLineEdit;
//    images_to_skip->setText("");

    QLabel *dataSourceLabel = new QLabel(tr("data_source:"));
    data_source = new QComboBox;
    data_source->addItem("APS");
    data_source->addItem("ESRF");
    data_source->addItem("SFRM");

    QLabel *dataTypeLabel = new QLabel(tr("data_type:"));
    data_type = new QComboBox;
    data_type->addItem("dark");
    data_type->addItem("laser_ON");
    data_type->addItem("laser_ON_OFF");
    data_type->addItem("laser_OFF_ON");

    QLabel *luInputdatasetNameLabel = new QLabel(tr("lu_input_assigned_dataset_name:"));
    lu_input_assigned_dataset_name = new QLineEdit;
    lu_input_assigned_dataset_name->setText("dataset__LU_assign_in.h5");

    QVBoxLayout *inputDataLayout = new QVBoxLayout;
    inputDataLayout->addWidget(imagesDirLabel);
    inputDataLayout->addWidget(images_directory);
    inputDataLayout->addWidget(logPathLabel);
    inputDataLayout->addWidget(log_file_path);
//    inputDataLayout->addWidget(skipImagesLabel);
//    inputDataLayout->addWidget(images_to_skip);
    inputDataLayout->addWidget(dataSourceLabel);
    inputDataLayout->addWidget(data_source);
    inputDataLayout->addWidget(dataTypeLabel);
    inputDataLayout->addWidget(data_type);
    inputDataLayout->addWidget(luInputdatasetNameLabel);
    inputDataLayout->addWidget(lu_input_assigned_dataset_name);
    inputDataLayout->addStretch();
    inputDataWidget->setLayout(inputDataLayout);

    /* OutputData page */
    QWidget *outputDataWidget = new QWidget;

    QLabel *outputDirLabel = new QLabel(tr("output_directory:"));
    output_directory = new QLineEdit;
    output_directory->setText("");

    QLabel *imageDatasetNameLabel = new QLabel(tr("images_dataset_name:"));
    images_dataset_name = new QLineEdit;
    images_dataset_name->setText("dataset__frm.h5");

    QLabel *signalDatasetNameLabel = new QLabel(tr("signal_dataset_name:"));
    signal_dataset_name = new QLineEdit;
    signal_dataset_name->setText("dataset__sig.h5");

    QLabel *integratedDirLabel = new QLabel(tr("integrated_dataset_name:"));
    integrated_dataset_name = new QLineEdit;
    integrated_dataset_name->setText("dataset__int.h5");

    QLabel *simulatedDatasetNameLabel = new QLabel(tr("simulated_dataset_name:"));
    simulated_dataset_name = new QLineEdit;
    simulated_dataset_name->setText("dataset__sim.h5");

    QLabel *luOutputDatasetNameLabel = new QLabel(tr("lu_output_expt_dataset_name:"));
    lu_output_expt_dataset_name = new QLineEdit;
    lu_output_expt_dataset_name->setText("dataset__LU_expt_out.h5");

    QVBoxLayout *outputDataLayout = new QVBoxLayout;
    outputDataLayout->addWidget(outputDirLabel);
    outputDataLayout->addWidget(output_directory);
    outputDataLayout->addWidget(imageDatasetNameLabel);
    outputDataLayout->addWidget(images_dataset_name);
    outputDataLayout->addWidget(signalDatasetNameLabel);
    outputDataLayout->addWidget(signal_dataset_name);
    outputDataLayout->addWidget(integratedDirLabel);
    outputDataLayout->addWidget(integrated_dataset_name);
    outputDataLayout->addWidget(simulatedDatasetNameLabel);
    outputDataLayout->addWidget(simulated_dataset_name);
    outputDataLayout->addWidget(luOutputDatasetNameLabel);
    outputDataLayout->addWidget(lu_output_expt_dataset_name);
    outputDataLayout->addStretch();
    outputDataWidget->setLayout(outputDataLayout);

    /* Integration page */
    QWidget *integrationWidget = new QWidget;

    QLabel *integrationMethodLabel = new QLabel(tr("integration_method:"));
    integration_method = new QComboBox;
    integration_method->addItem("SS");
    integration_method->addItem("KW");
    integration_method->addItem("CF");

    QLabel *trustLevelLabel = new QLabel(tr("SS method parameter - trust_level:"));
    trust_level = new QLineEdit;
    trust_level->setText("1.0");

    QLabel *signalLevelLabel = new QLabel(tr("SS method parameter - signal_level:"));
    signal_level = new QLineEdit;
    signal_level->setText("3.0");

    QLabel *alphaLabel = new QLabel(tr("KW method parameter - alpha:"));
    alpha = new QLineEdit;
    alpha->setText("0.05");

    QLabel *cutoffLevelLabel = new QLabel(tr("KW method parameter - cutoff_level:"));
    cutoff_level = new QLineEdit;
    cutoff_level->setText("3.0");

    QLabel *kwBlockLengthLabel = new QLabel(tr("KW method parameter - kw_block_length:"));
    kw_block_length = new QLineEdit;
    kw_block_length->setText("20");

    QLabel *rejectedRectangleskLabel = new QLabel(tr("rejected_rectangles:"));
    rejected_rectangles = new QLineEdit;
    rejected_rectangles->setText("({ x_0 = 0; y_0 = 1899; x_end = 1919; y_end = 2000; })");

    QLabel *rejectedGeneralRectanglesLabel = new QLabel(tr("rejected_general_rectangles:"));
    rejected_general_rectangles = new QLineEdit;
    rejected_general_rectangles->setText("({x_0 = 1000, y_0 = 1000, width = 1000, height = 50, angle = 10.0;})");

    QLabel *rejectedDiscsLabel = new QLabel(tr("rejected_discs:"));
    rejected_discs = new QLineEdit;
    rejected_discs->setText("({ x_0 = 1919; y_0 = 1919; R = 200; })");

    QLabel *rejectedDiscsComplementLabel = new QLabel(tr("rejected_discs_complement:"));
    rejected_discs_complement = new QLineEdit;
    rejected_discs_complement->setText("({ x_0 = 1024; y_0 =1024; R = 500; })");

    QLabel *rejectedBorderLabel = new QLabel(tr("rejected_border:"));
    rejected_border = new QLineEdit;
    rejected_border->setText("2");

    QLabel *removeIntersectedLabel = new QLabel(tr("remove_intersected:"));
    remove_intersected = new QComboBox;
    remove_intersected->addItem("TRUE");
    remove_intersected->addItem("FALSE");

    QLabel *minAmountOfPixelsLabel = new QLabel(tr("min_amount_of_pixels:"));
    min_amount_of_pixels = new QLineEdit;
    min_amount_of_pixels->setText("2");

    QLabel *morphologicalOperationsLabel = new QLabel(tr("morphological_operations:"));
    morphological_operations = new QLineEdit;
    morphological_operations->setText("peddh");

    QLabel *intensityWeightedCentersLabel = new QLabel(tr("intensity_weighted_centers:"));
    intensity_weighted_centers = new QComboBox;
    intensity_weighted_centers->addItem("TRUE");
    intensity_weighted_centers->addItem("FALSE");

    QLabel *sumOfBitmasksLabel = new QLabel(tr("sum_of_bitmasks:"));
    sum_of_bitmasks = new QComboBox;
    sum_of_bitmasks->addItem("FALSE");
    sum_of_bitmasks->addItem("TRUE");

    QLabel *amountInBlockLabel = new QLabel(tr("amount_in_block:"));
    amount_in_block = new QLineEdit;
    amount_in_block->setText("20");

    QLabel *primaryBeamNormalisationLabel = new QLabel(tr("primary_beam_normalisation:"));
    primary_beam_normalisation = new QComboBox;
    primary_beam_normalisation->addItem("FALSE");
    primary_beam_normalisation->addItem("TRUE");

    QLabel *backgroundCorrectionLabel = new QLabel(tr("background_correction:"));
    background_correction = new QComboBox;
    background_correction->addItem("FALSE");
    background_correction->addItem("TRUE");

    QLabel *verbosePixelGridLabel = new QLabel(tr("verbose_pixel_grid:"));
    verbose_pixel_grid = new QComboBox;
    verbose_pixel_grid->addItem("FALSE");
    verbose_pixel_grid->addItem("TRUE");

    QLabel *verbosePixelSizeNXLabel = new QLabel(tr("verbose_pixel_size_n_x:"));
    verbose_pixel_size_n_x = new QLineEdit;
    verbose_pixel_size_n_x->setText("5");

    QLabel *verbosePixelSizeNYLabel = new QLabel(tr("verbose_pixel_size_n_y:"));
    verbose_pixel_size_n_y = new QLineEdit;
    verbose_pixel_size_n_y->setText("5");

    QLabel *verboseSelectedPixelLabel = new QLabel(tr("verbose_selected_pixel:"));
    verbose_selected_pixel = new QLineEdit;
    verbose_selected_pixel->setText("({ x = 1858; y = 456; })");

    QLabel *saveBitmasksAsLabel = new QLabel(tr("save_bitmasks_as:"));
    save_bitmasks_as = new QComboBox;
    save_bitmasks_as->addItem("PNG");
    save_bitmasks_as->addItem("BMP");

    QVBoxLayout *integrationLayout1 = new QVBoxLayout;
    integrationLayout1->addWidget(integrationMethodLabel);
    integrationLayout1->addWidget(integration_method);
    integrationLayout1->addWidget(trustLevelLabel);
    integrationLayout1->addWidget(trust_level);
    integrationLayout1->addWidget(signalLevelLabel);
    integrationLayout1->addWidget(signal_level);
    integrationLayout1->addWidget(alphaLabel);
    integrationLayout1->addWidget(alpha);
    integrationLayout1->addWidget(cutoffLevelLabel);
    integrationLayout1->addWidget(cutoff_level);
    integrationLayout1->addWidget(kwBlockLengthLabel);
    integrationLayout1->addWidget(kw_block_length);
    integrationLayout1->addWidget(rejectedRectangleskLabel);
    integrationLayout1->addWidget(rejected_rectangles);
    integrationLayout1->addWidget(rejectedGeneralRectanglesLabel);
    integrationLayout1->addWidget(rejected_general_rectangles);
    integrationLayout1->addWidget(rejectedDiscsLabel);
    integrationLayout1->addWidget(rejected_discs);
    integrationLayout1->addWidget(rejectedDiscsComplementLabel);
    integrationLayout1->addWidget(rejected_discs_complement);
    integrationLayout1->addWidget(rejectedBorderLabel);
    integrationLayout1->addWidget(rejected_border);
    integrationLayout1->addWidget(removeIntersectedLabel);
    integrationLayout1->addWidget(remove_intersected);
    integrationLayout1->addStretch();

    QVBoxLayout *integrationLayout2 = new QVBoxLayout;
    integrationLayout2->addWidget(minAmountOfPixelsLabel);
    integrationLayout2->addWidget(min_amount_of_pixels);
    integrationLayout2->addWidget(morphologicalOperationsLabel);
    integrationLayout2->addWidget(morphological_operations);
    integrationLayout2->addWidget(intensityWeightedCentersLabel);
    integrationLayout2->addWidget(intensity_weighted_centers);
    integrationLayout2->addWidget(sumOfBitmasksLabel);
    integrationLayout2->addWidget(sum_of_bitmasks);
    integrationLayout2->addWidget(amountInBlockLabel);
    integrationLayout2->addWidget(amount_in_block);
    integrationLayout2->addWidget(primaryBeamNormalisationLabel);
    integrationLayout2->addWidget(primary_beam_normalisation);
    integrationLayout2->addWidget(backgroundCorrectionLabel);
    integrationLayout2->addWidget(background_correction);
    integrationLayout2->addWidget(verbosePixelGridLabel);
    integrationLayout2->addWidget(verbose_pixel_grid);
    integrationLayout2->addWidget(verbosePixelSizeNXLabel);
    integrationLayout2->addWidget(verbose_pixel_size_n_x);
    integrationLayout2->addWidget(verbosePixelSizeNYLabel);
    integrationLayout2->addWidget(verbose_pixel_size_n_y);
    integrationLayout2->addWidget(verboseSelectedPixelLabel);
    integrationLayout2->addWidget(verbose_selected_pixel);
    integrationLayout2->addWidget(saveBitmasksAsLabel);
    integrationLayout2->addWidget(save_bitmasks_as);
    integrationLayout2->addStretch();

    QGridLayout *integrationGridLayout = new QGridLayout;
    integrationGridLayout->addLayout(integrationLayout1, 0, 0);
    integrationGridLayout->addLayout(integrationLayout2, 0, 1);
    integrationWidget->setLayout(integrationGridLayout);

    /* Geomtery page */
    QWidget *geometryWidget = new QWidget;

    QLabel *detectorDistanceLabel = new QLabel(tr("detector_distance:"));
    detector_distance = new QLineEdit;
    detector_distance->setText("50.0");

    QLabel *beamCenterXLabel = new QLabel(tr("beam_center_x:"));
    beam_center_x = new QLineEdit;
    beam_center_x->setText("1000.38");

    QLabel *beamCenterYLabel = new QLabel(tr("beam_center_y:"));
    beam_center_y = new QLineEdit;
    beam_center_y->setText("1025.40");

    QLabel *pixelSizeXLabel = new QLabel(tr("pixel_size_x:"));
    pixel_size_x = new QLineEdit;
    pixel_size_x->setText("0.0792");

    QLabel *pixelSizeYLabel = new QLabel(tr("pixel_size_y:"));
    pixel_size_y = new QLineEdit;
    pixel_size_y->setText("0.0792");

    QLabel *alphaAngleLabel = new QLabel(tr("alpha_angle:"));
    alpha_angle = new QLineEdit;
    alpha_angle->setText("90.0");

    QLabel *betaAngleLabel = new QLabel(tr("beta_angle:"));
    beta_angle = new QLineEdit;
    beta_angle->setText("60.0");

    QLabel *omegaAngleLabel = new QLabel(tr("omega_angle:"));
    omega_angle = new QLineEdit;
    omega_angle->setText("20.0");

    QLabel *kappaAngleLabel = new QLabel(tr("kappa_angle:"));
    kappa_angle = new QLineEdit;
    kappa_angle->setText("35.0");

    QLabel *detectorDistanceInitialLabel = new QLabel(tr("detector_distance_initial:"));
    detector_distance_initial = new QLineEdit;
    detector_distance_initial->setText("50.0");

    QLabel *beamCenterXInitialLabel = new QLabel(tr("beam_center_x_initial:"));
    beam_center_x_initial = new QLineEdit;
    beam_center_x_initial->setText("1000.38");

    QLabel *beamCenterYInitialLabel = new QLabel(tr("beam_center_y_initial:"));
    beam_center_y_initial = new QLineEdit;
    beam_center_y_initial->setText("1025.40");

    QLabel *iterMaxLabel = new QLabel(tr("iter_max:"));
    iter_max = new QLineEdit;
    iter_max->setText("100");

    QLabel *dampingFactorLabel = new QLabel(tr("damping_factor:"));
    damping_factor = new QLineEdit;
    damping_factor->setText("0.5");

    QLabel *intensityCutoffLabel = new QLabel(tr("intensity_cutoff:"));
    intensity_cutoff = new QLineEdit;
    intensity_cutoff->setText("50.0");

    QLabel *matchingAngleLabel = new QLabel(tr("matching_angle:"));
    matching_angle = new QLineEdit;
    matching_angle->setText("0.1");

    QLabel *convergenceCriteriaLabel = new QLabel(tr("convergence_criteria:"));
    convergence_criteria = new QLineEdit;
    convergence_criteria->setText("0.5");

    QLabel *recalculatePairsLabel = new QLabel(tr("recalculate_pairs:"));
    recalculate_pairs = new QComboBox;
    recalculate_pairs->addItem("TRUE");
    recalculate_pairs->addItem("FALSE");

    QVBoxLayout *geometryLayout1 = new QVBoxLayout;
    geometryLayout1->addWidget(detectorDistanceLabel);
    geometryLayout1->addWidget(detector_distance);
    geometryLayout1->addWidget(beamCenterXLabel);
    geometryLayout1->addWidget(beam_center_x);
    geometryLayout1->addWidget(beamCenterYLabel);
    geometryLayout1->addWidget(beam_center_y);
    geometryLayout1->addWidget(pixelSizeXLabel);
    geometryLayout1->addWidget(pixel_size_x);
    geometryLayout1->addWidget(pixelSizeYLabel);
    geometryLayout1->addWidget(pixel_size_y);
    geometryLayout1->addWidget(alphaAngleLabel);
    geometryLayout1->addWidget(alpha_angle);
    geometryLayout1->addWidget(betaAngleLabel);
    geometryLayout1->addWidget(beta_angle);
    geometryLayout1->addWidget(omegaAngleLabel);
    geometryLayout1->addWidget(omega_angle);
    geometryLayout1->addWidget(kappaAngleLabel);
    geometryLayout1->addWidget(kappa_angle);
    geometryLayout1->addStretch();

    QVBoxLayout *geometryLayout2 = new QVBoxLayout;
    geometryLayout2->addWidget(detectorDistanceInitialLabel);
    geometryLayout2->addWidget(detector_distance_initial);
    geometryLayout2->addWidget(beamCenterXInitialLabel);
    geometryLayout2->addWidget(beam_center_x_initial);
    geometryLayout2->addWidget(beamCenterYInitialLabel);
    geometryLayout2->addWidget(beam_center_y_initial);
    geometryLayout2->addWidget(iterMaxLabel);
    geometryLayout2->addWidget(iter_max);
    geometryLayout2->addWidget(dampingFactorLabel);
    geometryLayout2->addWidget(damping_factor);
    geometryLayout2->addWidget(intensityCutoffLabel);
    geometryLayout2->addWidget(intensity_cutoff);
    geometryLayout2->addWidget(matchingAngleLabel);
    geometryLayout2->addWidget(matching_angle);
    geometryLayout2->addWidget(convergenceCriteriaLabel);
    geometryLayout2->addWidget(convergence_criteria);
    geometryLayout2->addWidget(recalculatePairsLabel);
    geometryLayout2->addWidget(recalculate_pairs);
    geometryLayout2->addStretch();

    QGridLayout *geometryGridLayout = new QGridLayout;
    geometryGridLayout->addLayout(geometryLayout1, 0, 0);
    geometryGridLayout->addLayout(geometryLayout2, 0, 1);
    geometryWidget->setLayout(geometryGridLayout);

    /* ratios page */
//    QWidget *ratiosWidget = new QWidget;

    /* Simulations page */
    QWidget *simulationsWidget = new QWidget;

    QLabel *simLambdaMinLabel = new QLabel(tr("sim_lambda_min:"));
    sim_lambda_min = new QLineEdit;
    sim_lambda_min->setText("0.8");

    QLabel *simLambdaMaxLabel = new QLabel(tr("sim_lambda_max:"));
    sim_lambda_max = new QLineEdit;
    sim_lambda_max->setText("1.0");

    QLabel *simSinthlMaxLabel = new QLabel(tr("sim_sinthl_max:"));
    sim_sinthl_max = new QLineEdit;
    sim_sinthl_max->setText("0.6");

    QLabel *simALabel = new QLabel(tr("sim_a:"));
    sim_a = new QLineEdit;
    sim_a->setText("10.0");

    QLabel *simBLabel = new QLabel(tr("sim_b:"));
    sim_b = new QLineEdit;
    sim_b->setText("10.0");

    QLabel *simCLabel = new QLabel(tr("sim_c:"));
    sim_c = new QLineEdit;
    sim_c->setText("10.0");

    QLabel *simAlphaLabel = new QLabel(tr("sim_alpha:"));
    sim_alpha = new QLineEdit;
    sim_alpha->setText("90.0");

    QLabel *simBetaLabel = new QLabel(tr("sim_beta:"));
    sim_beta = new QLineEdit;
    sim_beta->setText("90.0");

    QLabel *simGammaLabel = new QLabel(tr("sim_gamma:"));
    sim_gamma = new QLineEdit;
    sim_gamma->setText("90.0");

    QLabel *simDetectorDistanceLabel = new QLabel(tr("sim_detector_distance:"));
    sim_detector_distance = new QLineEdit;
    sim_detector_distance->setText("100.0");

    QLabel *simDetectorWidthLabel = new QLabel(tr("sim_detector_width:"));
    sim_detector_width = new QLineEdit;
    sim_detector_width->setText("3840");

    QLabel *simDetectorHeightLabel = new QLabel(tr("sim_detector_height:"));
    sim_detector_height = new QLineEdit;
    sim_detector_height->setText("3840");

    QLabel *simPixelSizeXLabel = new QLabel(tr("sim_pixel_size_x:"));
    sim_pixel_size_x = new QLineEdit;
    sim_pixel_size_x->setText("0.0792");

    QLabel *simPixelSizeYLabel = new QLabel(tr("sim_pixel_size_y:"));
    sim_pixel_size_y = new QLineEdit;
    sim_pixel_size_y->setText("0.0792");

    QLabel *simBeamCenterXLabel = new QLabel(tr("sim_beam_center_x:"));
    sim_beam_center_x = new QLineEdit;
    sim_beam_center_x->setText("1024");

    QLabel *simBeamCenterYLabel = new QLabel(tr("sim_beam_center_y:"));
    sim_beam_center_y = new QLineEdit;
    sim_beam_center_y->setText("1024");

    QLabel *simRunningAngleLabel = new QLabel(tr("sim_running_angle:"));
    sim_running_angle = new QComboBox;
    sim_running_angle->addItem("phi");
    sim_running_angle->addItem("chi");
    sim_running_angle->addItem("psi");

    QLabel *simAngleStartLabel = new QLabel(tr("sim_angle_start:"));
    sim_angle_start = new QLineEdit;
    sim_angle_start->setText("0.0");

    QLabel *simAngleStopLabel = new QLabel(tr("sim_angle_stop:"));
    sim_angle_stop = new QLineEdit;
    sim_angle_stop->setText("90.0");

    QLabel *simAngleStepLabel = new QLabel(tr("sim_angle_step:"));
    sim_angle_step = new QLineEdit;
    sim_angle_step->setText("1.0");

    QLabel *simOmegaAngleLabel = new QLabel(tr("sim_omega_angle:"));
    sim_omega_angle = new QLineEdit;
    sim_omega_angle->setText("0.0");

    QLabel *simChiAngleLabel = new QLabel(tr("sim_chi_angle:"));
    sim_chi_angle = new QLineEdit;
    sim_chi_angle->setText("-90.0");

    QLabel *simPhiAngleLabel = new QLabel(tr("sim_phi_angle:"));
    sim_phi_angle = new QLineEdit;
    sim_phi_angle->setText("0.0");

    QLabel *simUOmegaAngleLabel = new QLabel(tr("sim_u_omega_angle:"));
    sim_u_omega_angle = new QLineEdit;
    sim_u_omega_angle->setText("0.0");

    QLabel *simUChiAngleLabel = new QLabel(tr("sim_u_chi_angle:"));
    sim_u_chi_angle = new QLineEdit;
    sim_u_chi_angle->setText("0.0");

    QLabel *simUPhiAngleLabel = new QLabel(tr("sim_u_phi_angle:"));
    sim_u_phi_angle = new QLineEdit;
    sim_u_phi_angle->setText("0.0");

    QLabel *simExportImagesLabel = new QLabel(tr("sim_export_images:"));
    sim_export_images = new QComboBox;
    sim_export_images->addItem("TRUE");
    sim_export_images->addItem("FALSE");

    QVBoxLayout *simulationsLayout1 = new QVBoxLayout;
    simulationsLayout1->addWidget(simLambdaMinLabel);
    simulationsLayout1->addWidget(sim_lambda_min);
    simulationsLayout1->addWidget(simLambdaMaxLabel);
    simulationsLayout1->addWidget(sim_lambda_max);
    simulationsLayout1->addWidget(simSinthlMaxLabel);
    simulationsLayout1->addWidget(sim_sinthl_max);
    simulationsLayout1->addWidget(simALabel);
    simulationsLayout1->addWidget(sim_a);
    simulationsLayout1->addWidget(simBLabel);
    simulationsLayout1->addWidget(sim_b);
    simulationsLayout1->addWidget(simCLabel);
    simulationsLayout1->addWidget(sim_c);
    simulationsLayout1->addWidget(simAlphaLabel);
    simulationsLayout1->addWidget(sim_alpha);
    simulationsLayout1->addWidget(simBetaLabel);
    simulationsLayout1->addWidget(sim_beta);
    simulationsLayout1->addWidget(simGammaLabel);
    simulationsLayout1->addWidget(sim_gamma);
    simulationsLayout1->addWidget(simDetectorDistanceLabel);
    simulationsLayout1->addWidget(sim_detector_distance);
    simulationsLayout1->addWidget(simDetectorWidthLabel);
    simulationsLayout1->addWidget(sim_detector_width);
    simulationsLayout1->addWidget(simDetectorHeightLabel);
    simulationsLayout1->addWidget(sim_detector_height);
    simulationsLayout1->addWidget(simPixelSizeXLabel);
    simulationsLayout1->addWidget(sim_pixel_size_x);
    simulationsLayout1->addWidget(simPixelSizeYLabel);
    simulationsLayout1->addWidget(sim_pixel_size_y);
    simulationsLayout1->addStretch();

    QVBoxLayout *simulationsLayout2 = new QVBoxLayout;
    simulationsLayout2->addWidget(simBeamCenterXLabel);
    simulationsLayout2->addWidget(sim_beam_center_x);
    simulationsLayout2->addWidget(simBeamCenterYLabel);
    simulationsLayout2->addWidget(sim_beam_center_y);
    simulationsLayout2->addWidget(simRunningAngleLabel);
    simulationsLayout2->addWidget(sim_running_angle);
    simulationsLayout2->addWidget(simAngleStartLabel);
    simulationsLayout2->addWidget(sim_angle_start);
    simulationsLayout2->addWidget(simAngleStopLabel);
    simulationsLayout2->addWidget(sim_angle_stop);
    simulationsLayout2->addWidget(simAngleStepLabel);
    simulationsLayout2->addWidget(sim_angle_step);
    simulationsLayout2->addWidget(simOmegaAngleLabel);
    simulationsLayout2->addWidget(sim_omega_angle);
    simulationsLayout2->addWidget(simChiAngleLabel);
    simulationsLayout2->addWidget(sim_chi_angle);
    simulationsLayout2->addWidget(simPhiAngleLabel);
    simulationsLayout2->addWidget(sim_phi_angle);
    simulationsLayout2->addWidget(simUOmegaAngleLabel);
    simulationsLayout2->addWidget(sim_u_omega_angle);
    simulationsLayout2->addWidget(simUChiAngleLabel);
    simulationsLayout2->addWidget(sim_u_chi_angle);
    simulationsLayout2->addWidget(simUPhiAngleLabel);
    simulationsLayout2->addWidget(sim_u_phi_angle);
    simulationsLayout2->addWidget(simExportImagesLabel);
    simulationsLayout2->addWidget(sim_export_images);
    simulationsLayout2->addStretch();

    QGridLayout *simulationsGridLayout = new QGridLayout;
    simulationsGridLayout->addLayout(simulationsLayout1, 0, 0);
    simulationsGridLayout->addLayout(simulationsLayout2, 0, 1);
    simulationsWidget->setLayout(simulationsGridLayout);

    /* Machine page */
    QWidget *machineWidget = new QWidget;

    QLabel *maxHostMemoryLabel = new QLabel(tr("max_host_memory:"));
    max_host_memory = new QLineEdit;
    max_host_memory->setText("512");

    QLabel *maxDeviceMemoryLabel = new QLabel(tr("max_device_memory:"));
    max_device_memory = new QLineEdit;
    max_device_memory->setText("1024");

    QVBoxLayout *machineLayout = new QVBoxLayout;
    machineLayout->addWidget(maxHostMemoryLabel);
    machineLayout->addWidget(max_host_memory);
    machineLayout->addWidget(maxDeviceMemoryLabel);
    machineLayout->addWidget(max_device_memory);
    machineLayout->addStretch();
    machineWidget->setLayout(machineLayout);

    /* Main QTabWidget */
    QTabWidget *configurationTabWidget = new QTabWidget;
    configurationTabWidget->addTab(inputDataWidget, "inputData");
    configurationTabWidget->addTab(outputDataWidget, "outputData");
    configurationTabWidget->addTab(integrationWidget, "integration");
    configurationTabWidget->addTab(geometryWidget, "geometry");
//    configurationTabWidget->addTab(ratiosWidget, "ratios");
    configurationTabWidget->addTab(simulationsWidget, "simulations");
    configurationTabWidget->addTab(machineWidget, "machine");

    QVBoxLayout *layoutDialog = new QVBoxLayout;
    saveButton = new QPushButton(tr("&Save"));
    connect(saveButton, &QPushButton::clicked, this, &ConfigurationDialog::saveConfiguration);
    layoutDialog->addWidget(configurationTabWidget);
    layoutDialog->addWidget(saveButton);
    setLayout(layoutDialog);
}

void ConfigurationDialog::saveConfiguration()
{
    /* READ ALL OPTIONS FOR CONFIGURATION */
    QString images_directory_text = images_directory->text();
    QString log_file_path_text = log_file_path->text();
//    QString images_to_skip_text = images_to_skip->text();
    QString data_source_text = data_source->currentText();
    QString data_type_text = data_type->currentText();
    QString lu_input_assigned_dataset_name_text = lu_input_assigned_dataset_name->text();

    QString output_directory_text = output_directory->text();
    QString images_dataset_name_text = images_dataset_name->text();
    QString signal_dataset_name_text = signal_dataset_name->text();
    QString integrated_dataset_name_text = integrated_dataset_name->text();
    QString simulated_dataset_name_text = simulated_dataset_name->text();
    QString lu_output_expt_dataset_name_text = lu_output_expt_dataset_name->text();

    QString integration_method_text = integration_method->currentText();
    QString trust_level_text = trust_level->text();
    QString signal_level_text = signal_level->text();
    QString alpha_text = alpha->text();
    QString cutoff_level_text = cutoff_level->text();
    QString kw_block_length_text = kw_block_length->text();
    QString rejected_rectangles_text = rejected_rectangles->text();
    QString rejected_general_rectangles_text = rejected_general_rectangles->text();
    QString rejected_discs_text = rejected_discs->text();
    QString rejected_discs_complement_text = rejected_discs_complement->text();
    QString rejected_border_text = rejected_border->text();
    QString remove_intersected_text = remove_intersected->currentText();
    QString min_amount_of_pixels_text = min_amount_of_pixels->text();
    QString morphological_operations_text = morphological_operations->text();
    QString intensity_weighted_centers_text = intensity_weighted_centers->currentText();
    QString sum_of_bitmasks_text = sum_of_bitmasks->currentText();
    QString amount_in_block_text = amount_in_block->text();
    QString primary_beam_normalisation_text = primary_beam_normalisation->currentText();
    QString background_correction_text = background_correction->currentText();
    QString verbose_pixel_grid_text = verbose_pixel_grid->currentText();
    QString verbose_pixel_size_n_x_text = verbose_pixel_size_n_x->text();
    QString verbose_pixel_size_n_y_text = verbose_pixel_size_n_y->text();
    QString verbose_selected_pixel_text = verbose_selected_pixel->text();
    QString save_bitmasks_as_text = save_bitmasks_as->currentText();

    QString detector_distance_text = detector_distance->text();
    QString beam_center_x_text = beam_center_x->text();
    QString beam_center_y_text = beam_center_y->text();
    QString pixel_size_x_text = pixel_size_x->text();
    QString pixel_size_y_text = pixel_size_y->text();
    QString alpha_angle_text = alpha_angle->text();
    QString beta_angle_text = beta_angle->text();
    QString omega_angle_text = omega_angle->text();
    QString kappa_angle_text = kappa_angle->text();
    QString detector_distance_initial_text = detector_distance_initial->text();
    QString beam_center_x_initial_text = beam_center_x_initial->text();
    QString beam_center_y_initial_text = beam_center_y_initial->text();
    QString iter_max_text = iter_max->text();
    QString damping_factor_text = damping_factor->text();
    QString intensity_cutoff_text = intensity_cutoff->text();
    QString matching_angle_text = matching_angle->text();
    QString convergence_criteria_text = convergence_criteria->text();
    QString recalculate_pairs_text = recalculate_pairs->currentText();

    QString sim_lambda_min_text = sim_lambda_min->text();
    QString sim_lambda_max_text = sim_lambda_max->text();
    QString sim_sinthl_max_text = sim_sinthl_max->text();
    QString sim_a_text = sim_a->text();
    QString sim_b_text = sim_b->text();
    QString sim_c_text = sim_c->text();
    QString sim_alpha_text = sim_alpha->text();
    QString sim_beta_text = sim_beta->text();
    QString sim_gamma_text = sim_gamma->text();
    QString sim_detector_distance_text = sim_detector_distance->text();
    QString sim_detector_width_text = sim_detector_width->text();
    QString sim_detector_height_text = sim_detector_height->text();
    QString sim_pixel_size_x_text = sim_pixel_size_x->text();
    QString sim_pixel_size_y_text = sim_pixel_size_y->text();
    QString sim_beam_center_x_text = sim_beam_center_x->text();
    QString sim_beam_center_y_text = sim_beam_center_y->text();
    QString sim_running_angle_text = sim_running_angle->currentText();
    QString sim_angle_start_text = sim_angle_start->text();
    QString sim_angle_stop_text = sim_angle_stop->text();
    QString sim_angle_step_text = sim_angle_step->text();
    QString sim_omega_angle_text = sim_omega_angle->text();
    QString sim_chi_angle_text = sim_chi_angle->text();
    QString sim_phi_angle_text = sim_phi_angle->text();
    QString sim_u_omega_angle_text = sim_u_omega_angle->text();
    QString sim_u_chi_angle_text = sim_u_chi_angle->text();
    QString sim_u_phi_angle_text = sim_u_phi_angle->text();
    QString sim_export_images_text = sim_export_images->currentText();

    QString max_host_memory_text = max_host_memory->text();
    QString max_device_memory_text = max_device_memory->text();


    /* CHECK FIELDS THAT ARE REQUIRED */
    if (images_directory_text.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("\"images_directory\" field is required"));
        return;
    }
    if (log_file_path_text.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("\"log_file_path\" field is required"));
        return;
    }
    if (output_directory_text.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("\"output_directory\" field is required"));
        return;
    }

    /* OPEN DIALOG FOR STREAMING TO FILE */
    pathToSaveConfiguration = QFileDialog::getSaveFileName(this,
        tr("Save Configuration File"), "",
        tr("input file (*.inp);;configuration file (*.cfg);;All Files (*)"));
    if (pathToSaveConfiguration.isEmpty())
        return;

    QFile file(pathToSaveConfiguration);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open a file"),
            file.errorString());
        return;
    }

    /* STREAMING DATA INTO FILE */
    QTextStream out(&file);
    out << "input_data =" << '\n'<< "{" << '\n';
    out << "\timages_directory = \"" << images_directory_text << "\";" << '\n';
    out << "\tlog_file_path = \""    << log_file_path_text << "\";" << '\n';
//    out << "\timages_to_skip = \""   << images_to_skip_text << "\";" << '\n';
    out << "\tdata_source = \"" << data_source_text << "\";" << '\n';
    out << "\tdata_type = \"" << data_type_text << "\";" << '\n';
    out << "\tlu_input_assigned_dataset_name = \"" << lu_input_assigned_dataset_name_text << "\";" << '\n';
    out << "};" << '\n' << '\n';

    out << "output_data =" << '\n'<< "{" << '\n';
    out << "\toutput_directory = \"" << output_directory_text << "\";" << '\n';
    out << "\timages_dataset_name = \""    << images_dataset_name_text << "\";" << '\n';
    out << "\tsignal_dataset_name = \""   << signal_dataset_name_text << "\";" << '\n';
    out << "\tintegrated_dataset_name = \"" << integrated_dataset_name_text << "\";" << '\n';
    out << "\tsimulated_dataset_name = \"" << simulated_dataset_name_text << "\";" << '\n';
    out << "\tlu_output_expt_dataset_name = \"" << lu_output_expt_dataset_name_text << "\";" << '\n';
    out << "};" << '\n' << '\n';

    out << "integration =" << '\n'<< "{" << '\n';
    out << "\tintegration_method = \"" << integration_method_text << "\";" << '\n';
    out << "\ttrust_level = "    << trust_level_text << ";" << '\n';
    out << "\tsignal_level = "   << signal_level_text << ";" << '\n';
    out << "\talpha = " << alpha_text << ";" << '\n';
    out << "\tcutoff_level = " << cutoff_level_text << ";" << '\n';
    out << "\tkw_block_length = " << kw_block_length_text << ";" << '\n';
    out << "\trejected_rectangles = " << rejected_rectangles_text << ";" << '\n';
    out << "\trejected_general_rectangles = "    << rejected_general_rectangles_text << ";" << '\n';
    out << "\trejected_discs = "   << rejected_discs_text << ";" << '\n';
    out << "\trejected_discs_complement = " << rejected_discs_complement_text << ";" << '\n';
    out << "\trejected_border = " << rejected_border_text << ";" << '\n';
    out << "\tremove_intersected = " << remove_intersected_text << ";" << '\n';
    out << "\tmin_amount_of_pixels = "   << min_amount_of_pixels_text << ";" << '\n';
    out << "\tmorphological_operations = \"" << morphological_operations_text << "\";" << '\n';
    out << "\tintensity_weighted_centers = " << intensity_weighted_centers_text << ";" << '\n';
    out << "\tsum_of_bitmasks = " << sum_of_bitmasks_text << ";" << '\n';
    out << "\tamount_in_block = " << amount_in_block_text << ";" << '\n';
    out << "\tprimary_beam_normalisation = " << primary_beam_normalisation_text << ";" << '\n';
    out << "\tbackground_correction = " << background_correction_text << ";" << '\n';
    out << "\tverbose_pixel_grid = " << verbose_pixel_grid_text << ";" << '\n';
    out << "\tverbose_pixel_size_n_x = " << verbose_pixel_size_n_x_text << ";" << '\n';
    out << "\tverbose_pixel_size_n_y = " << verbose_pixel_size_n_y_text << ";" << '\n';
    out << "\tverbose_selected_pixel = " << verbose_selected_pixel_text << ";" << '\n';
    out << "\tsave_bitmasks_as = \"" << save_bitmasks_as_text << "\";" << '\n';
    out << "};" << '\n' << '\n';

    out << "geometry =" << '\n'<< "{" << '\n';
    out << "\tdetector_distance = " << detector_distance_text << ";" << '\n';
    out << "\tbeam_center_x = "    << beam_center_x_text << ";" << '\n';
    out << "\tbeam_center_y = "   << beam_center_y_text << ";" << '\n';
    out << "\tpixel_size_x = " << pixel_size_x_text << ";" << '\n';
    out << "\tpixel_size_y = " << pixel_size_y_text << ";" << '\n';
    out << "\talpha_angle = " << alpha_angle_text << ";" << '\n';
    out << "\tbeta_angle = " << beta_angle_text << ";" << '\n';
    out << "\tomega_angle = " << omega_angle_text << ";" << '\n';
    out << "\tkappa_angle = "    << kappa_angle_text << ";" << '\n';
    out << "\tdetector_distance_initial = "   << detector_distance_initial_text << ";" << '\n';
    out << "\tbeam_center_x_initial = " << beam_center_x_initial_text << ";" << '\n';
    out << "\tbeam_center_y_initial = " << beam_center_y_initial_text << ";" << '\n';
    out << "\titer_max = " << iter_max_text << ";" << '\n';
    out << "\tdamping_factor = "   << damping_factor_text << ";" << '\n';
    out << "\tintensity_cutoff = "    << intensity_cutoff_text << ";" << '\n';
    out << "\tmatching_angle = "   << matching_angle_text << ";" << '\n';
    out << "\tconvergence_criteria = " << convergence_criteria_text << ";" << '\n';
    out << "\trecalculate_pairs = "   << recalculate_pairs_text << ";" << '\n';
    out << "};" << '\n' << '\n';

    out << "simulation =" << '\n'<< "{" << '\n';
    out << "\tsim_lambda_min = " << sim_lambda_min_text << ";" << '\n';
    out << "\tsim_lambda_max = " << sim_lambda_max_text << ";" << '\n';
    out << "\tsim_sinthl_max = " << sim_sinthl_max_text << ";" << '\n';
    out << "\tsim_a = " << sim_a_text << ";" << '\n';
    out << "\tsim_b = " << sim_b_text << ";" << '\n';
    out << "\tsim_c = " << sim_c_text << ";" << '\n';
    out << "\tsim_alpha = " << sim_alpha_text << ";" << '\n';
    out << "\tsim_beta = " << sim_beta_text << ";" << '\n';
    out << "\tsim_gamma = " << sim_gamma_text << ";" << '\n';
    out << "\tsim_detector_distance = " << sim_detector_distance_text << ";" << '\n';
    out << "\tsim_detector_width = " << sim_detector_width_text << ";" << '\n';
    out << "\tsim_detector_height = " << sim_detector_height_text << ";" << '\n';
    out << "\tsim_pixel_size_x = " << sim_pixel_size_x_text << ";" << '\n';
    out << "\tsim_pixel_size_y = " << sim_pixel_size_y_text << ";" << '\n';
    out << "\tsim_beam_center_x = " << sim_beam_center_x_text << ";" << '\n';
    out << "\tsim_beam_center_y = " << sim_beam_center_y_text << ";" << '\n';
    out << "\tsim_running_angle = \"" << sim_running_angle_text << "\";" << '\n';
    out << "\tsim_angle_start = " << sim_angle_start_text << ";" << '\n';
    out << "\tsim_angle_stop = " << sim_angle_stop_text << ";" << '\n';
    out << "\tsim_angle_step = " << sim_angle_step_text << ";" << '\n';
    out << "\tsim_omega_angle = " << sim_omega_angle_text << ";" << '\n';
    out << "\tsim_chi_angle = " << sim_chi_angle_text << ";" << '\n';
    out << "\tsim_phi_angle = " << sim_phi_angle_text << ";" << '\n';
    out << "\tsim_u_omega_angle = " << sim_u_omega_angle_text << ";" << '\n';
    out << "\tsim_u_chi_angle = " << sim_u_chi_angle_text << ";" << '\n';
    out << "\tsim_u_phi_angle = " << sim_u_phi_angle_text << ";" << '\n';
    out << "\tsim_export_images = " << sim_export_images_text << ";" << '\n';
    out << "};" << '\n' << '\n';

    out << "machine =" << '\n'<< "{" << '\n';
    out << "\tmax_host_memory = " << max_host_memory_text << ";" << '\n';
    out << "\tmax_device_memory = " << max_device_memory_text << ";" << '\n';
    out << "};" << '\n';

    QMessageBox::information(this, tr("Save Configuration File"),
        tr("File saved under: \"%1\"").arg(pathToSaveConfiguration));
    done(1); //value for QDialog::Accepted
}
