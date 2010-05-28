<?php

/**
 * Returns term descriptions for "Research Interests" vocabulary
 * @return array
 */
function _gkimport_pub_term_descriptions(){
  return array(
  'Causal Inference' => 'Methods for detecting and reducing model dependence (when minor model changes produce substantively different inferences) in inferring counterfactuals. Matching methods; "politically robust" and cluster-randomized experimental designs; causal bias decompositions.',
  'Content Analysis' => 'Automated methods of extracting information from text documents and for correcting for errors by human coders.',
  'Data Sharing and Informatics' => 'New standards, protocols, and software for citing, sharing, analyzing, archiving, preserving, distributing, cataloging, translating, disseminating, naming, verifying, and replicating quantitative data and associated analyses. Also includes proposals to improve the norms of data sharing and replication in science.',
  'Ecological Inference' => '(Inferring Individual Behavior from Group-Level Data): The original methods that incorporate both unit-level deterministic bounds and cross-unit statistical information, methods for 2x2 and larger tables, Bayesian model averaging, applications to elections, EI/EzI software.',
  'Event Counts and Duration Models' => 'Develops statistical models to explain how many events occur for each fixed time period, or the time between events. An application to cabinet dissolution in parliamentary democracies united two previously waring scholarly literatures. Other applications in international relations, and Supreme Court appointments.',
  'Incumbency Advantage' => 'Proof that previously used estimators of the electoral advantage of having served in office before were biased, and a new unbiased estimator. Also, the first systematic demonstration that constituency service by legislators increases the incumbency advantage.',
  'International Conflict' => 'Evidence that the causes of conflict, theorized to be important but often found to be small or ephemeral, are indeed tiny for the vast majority of dyads, but they are large, stable, and replicable wherever the ex ante probability of conflict is large. Also methods for coding, analyzing, and forecasting international conflict and state failure.',
  'Legislative Redistricting' => 'Defining partisan symmetry as a standard for fairness; measuring partisan bias and electoral responsiveness; discussion of U.S. Supreme Court rulings on this work. Evidence that U.S. redistricting reduces bias and increases responsiveness, and that the electoral college is fair; applications to legislatures, primaries, and multiparty systems; JudgeIt Software.',
  'Missing Data' => 'Statistical methods to accommodate missing information in data sets due to scattered nonresponse or to entire missing survey questions. Introduces the first fast and easy-to-use algorithm for multiple imputation, resulting in the widespread use of both. Applications to electoral, and other compositional data.',
  'Mortality Studies' => 'Methods for estimating cause-specific and overall mortality rates in areas without vital registration; forecasting mortality rates (hierarchically, for time series data cross-classified by age, sex, country, and cause); measuring inequality in risk of death.',
  'Presidency Research, and Voting Behavior' => 'Resolution of the paradox of why polls are so variable over time during presidential campaigns even though the vote outcome is easily predictable before it starts. Also, a resolution of a key controversy over absentee ballots during the 2000 presidential election; and the methodology of small-n research on executives.',
  'Qualitative Research' => 'How the same unified theory of inference underlies quantitative and qualitative research alike; scientific inference when quantification is difficult or impossible; research design; empirical research in legal scholarship.',
  'Rare Events' => 'How to save 99% of your data collection costs; bias corrections for logistic regression in estimating probabilities and causal effects in rare events data; estimating base probabilities or any quantity from case-control data; automated coding of events.',
  'Survey Research' => '"Anchoring Vignette" methods for when different respondents (perhaps from different cultures, countries, or ethnic groups) understand survey questions in different ways; an approach to developing theoretical definitions of complicated concepts apparently definable only by example (i.e., "you know it when you see it"); how surveys work.',
  'Unifying Statistical Analysis' => 'Development of a unified approach to statistical modeling, inference, interpretation, presentation, analysis, and software; integrated with most of the other projects listed here.',
  );

}

/**
 * Returns second level term descriptions for "Research Interests" vocabulary
 * @return array
 */
function _gkimport_pub_second_term_descriptions(){
  return array(
  'Causal Inference' => array(
  'Methods for Observational Data' => '',
  'Experimental Design' => '',
  'Software' => '',
  'Applications' => '',
  ),

  'Content Analysis' => array(
  'Software' => '',
  'Data' => '',
  ),

  'Data Sharing and Informatics'  => array(
  'Related Papers on New Forms of Data' => '',
  'Dataverse Network Project' => 'a major ongoing project to write web applications, standards, protocols, and software for automating the process of citing, archiving, preserving, distributing, cataloging, translating, disseminating, naming, verifying, and replicating data and associated analyses',
  'The Virtual Data Center' => 'the predecessor to the Dataverse Network',
  ),

  'Ecological Inference'  => array(
  'Methods' => '',
  'Software' => '',
  'Data' => '',
  'Discussions and Extensions'  => '',
  ),

  'Event Counts and Duration Models'  => array(
  'Event Counts' => 'A series of methods that introduced existing, and developed new, statistical models for event counts for political science research.',
  'Duration of Parliamentary Governments' => 'A statistical model, and related work, that united two waring scholarly literatures.',
  'Software' => '',
  'Related Data' => '',
  ),

  'Incumbency Advantage'  => array(
  'How to Estimate the Electoral Advantage of Incumbency' => '',
  'Causes and Consequences' => '',
  'Data' => '',
  ),

  'International Conflict'  => array(
  ),

  'Legislative Redistricting'  => array(
  'U.S. Legislatures' => '',
  'Other Districting Systems' => '',
  'Software' => '',
  'Data' => '',
  ),

  'Missing Data'  => array(
  'Methods' => '',
  'Software' => '',
  'How Surveys Work' => '',
  ),

  'Mortality Studies'  => array(
  'Forecasting Mortality' => '',
  'Estimating Overall and Cause-Specific Mortality Rates' => 'Inexpensive methods of estimating the overall and cause-specific mortality rates from surveys when vital registration (death certificates) or other monitoring is unavailable or inadequate.',
  'Uses of Mortality Rates' => '',
  ),

  'Presidency Research and Voting Behavior'  => array(
  'Voting Behavior' => '',
  'Presidency Research' => '',
  ),

  'Qualitative Research'  => array(
  'Scientific Inference in Qualitative Research' => '',
  'In Legal Research' => '',
  ),

  'Rare Events'  => array(
  'Case Control and Rare Events Bias Corrections' => '',
  'Automatic Coding of Rare Events' => '',
  'Software' => '',
  'Data' => '',
  ),

  'Survey Research'  => array(
  'Anchoring Vignettes' => 'Methods for when different respondents (perhaps from different cultures, countries, or ethnic groups), or respondents and investigators, understand survey questions in different ways. Also includes an approach to developing theoretical definitions of complicated concepts apparently definable only by example (i.e., "you know it when you see it").',
  'How Surveys Work' => '',
  'Related Research' => '',
  ),

  'Unifying Statistical Analysis'  => array(
  'Related Materials' => '',
  ),
  );
}

/**
 * Returns third level term descriptions for "Research Interests" vocabulary
 * @return array
 */
function _gkimport_pub_third_term_descriptions(){
  return array(
  'Methods for Observational Data ' => array(
  'Evaluating Methods' => 'whether counterfactual questions (predictions, what-if questions, and causal effects) can be reasonably answered from given data, or whether inferences will instead be highly model-dependent; also, a new decomposition of bias in causal inference. These articles overlap (and each as been the subject of a journal symposium)',
  'Matching Methods ' => '',
  ),

  'U.S. Legislatures' => array(
  'partisan symmetry' => 'The concept of partisan symmetry as a standard for assessing partisan gerrymandering',
  'methods for measuring partisan bias and electoral responsiveness' => 'The methods for measuring partisan bias and electoral responsiveness, and related quantities, that first relaxed the assumptions of exact uniform partisan swing and the exact correspondence between statewide electoral results and legislative electoral results, among other improvements',
  'paradoxical benefits of redistricting' => 'Demonstrates the paradoxical benefits of redistricting to American democracy, even partisan gerrymandering, (as compared to no redistricting) in reducing partian bias and increasing electoral responsiveness. (Of course, if the symmetry standard were imposed, redistricting by any means would produce less bias than any other arrangement.)',
  ),
  );
}


function _gkimport_undo_sub_terms(){
  $res = db_query("SELECT tid FROM {term_hierarchy} WHERE parent != %d", 0);
  while($data = db_fetch_object($res)){
    //delete the term
    taxonomy_del_term($data -> tid);
  }
}
